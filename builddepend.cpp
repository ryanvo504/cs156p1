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
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++)
    {
        string line;
        vector<string> split;
        getline(cin,line);
        string s;
        stringstream stream(line);
        while (getline(stream,s, ' ')) // parse each depending file by whitespaces
        {
                split.push_back(s);
        }
        split[0].pop_back(); //pop off colon from first file
        if (split.size() > 1)
        {
            for (int j = 1; j < split.size() - 1; j++)
            {
                        g.addEdge(split[j],split[0]); // add edges backwards
            }
        }
    }
    string start;
    cin >> start; // get affected file
    g.dfs(start); // dfs on changed file to find affected files 
    return 0;
}