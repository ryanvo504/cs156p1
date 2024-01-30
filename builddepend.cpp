#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

class Graph
{
    public: 
        int clock;
        int count;
        vector<string> files;
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> vis;
        unordered_map<string, int> post;
        unordered_map<string, int> pre;
        queue<string> ans;
        void dfs(string x);
        void explore(string x);
        void addEdge(string src, string dest);
};


void Graph::addEdge(string src, string dest)
{
    adj[src].push_back(dest);
}

void Graph::explore(string x)
{
    ans.push(x);
    vis[x] = true;
    pre[x] = clock;
    clock++;
    for (string y: adj[x])
    {
        if (!vis[y])
            explore(y);
    }
    post[x] = clock;
    clock++;

}

void Graph::dfs(string x)
{
    ans.push(x);
    vis[x] = true;
    while (!ans.empty())
    {
        string temp = ans.front();
        ans.pop();
        cout << temp << endl;
        for (string y : adj[temp])
        {
            if (!vis[y])
            {
                ans.push(y);
                vis[y] = true;
            }
        }
    }


    

}



int main()
{
    Graph g;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
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
        g.files.push_back(split[0]);
        if (split.size() > 1)
        {
            for (int j = 1; j < split.size(); j++)
            {
                        g.addEdge(split[j],split[0]); // add edge backwards
            }
        }
    }
    string start;
    cin >> start; // get affected file
    g.dfs(start); // dfs on changed file to find affected files
    return 0;
}