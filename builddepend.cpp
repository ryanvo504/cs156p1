#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <fstream>


using namespace std;

class Graph
{
    public: 
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> vis;
        void dfs(string x);
        void addEdge(string src, string dest);
};


void Graph::addEdge(string src, string dest)
{
    adj[src].push_back(dest);
}

void Graph::dfs(string x)
{
    vis[x] = true;
    cout << x << endl;
    for (string y: adj[x])
    {
        if (!vis[y])
            dfs(y);
    }
}



int main()
{
    Graph g;
    string line;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin,line);
        size_t pos = line.find(":"); // parse name of file without colon
        string temp = line.substr(0,pos);
        if (line.length() > pos + 2) // checking for trailing files after name of file
        {
            line = line.substr(pos + 2); // parse rest of line skipping : and whitespace
            stringstream stream(line);
            while (getline(stream,line, ' ')) // parse each depending file by whitespaces
            {
                g.addEdge(line,temp); // add edges backwards
            }
        }
    }
    cin >> line; // get affected file
    g.dfs(line); // dfs on changed file to find affected files 
    return 0;
}