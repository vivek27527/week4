#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> variables = {"A","B","C","D"};
vector<string> colors = {"Red","Green","Blue"};

map<string, vector<string>> neighbors = {
    {"A", {"B","C"}},
    {"B", {"A","C","D"}},
    {"C", {"A","B","D"}},
    {"D", {"B","C"}}
};

map<string,string> assignment;

bool isValid(string var, string color)
{
    for(string n : neighbors[var])
    {
        if(assignment[n] == color)
            return false;
    }
    return true;
}

bool backtrack(int index)
{
    if(index == variables.size())
        return true;

    string var = variables[index];

    for(string color : colors)
    {
        if(isValid(var, color))
        {
            assignment[var] = color;

            if(backtrack(index + 1))
                return true;

            assignment[var] = "";
        }
    }

    return false;
}

int main()
{
    if(backtrack(0))
    {
        cout<<"Solution:\n";
        for(auto x : assignment)
            cout<<x.first<<" -> "<<x.second<<endl;
    }
    else
    {
        cout<<"No Solution Found";
    }

    return 0;
}
