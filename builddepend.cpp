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
        vector<string> bfs(string x);
        void explore(string x);
        void addEdge(string src, string dest);
};


void Graph::addEdge(string src, string dest)
{
    adj[src].push_back(dest);
}

vector<string> Graph::bfs(string start) {
        vector<string> recompiled;
        queue<string> q;
        
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            string file = q.front();
            q.pop();

            for (string dep : adj[file]) {
                if (!vis[dep]) {
                    q.push(dep);
                    vis[dep] = true;
                }
            }
            recompiled.push_back(file);
        }

        return recompiled;
}







int main()
{
    ios_base::sync_with_stdio(false); 
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
            if (split.size() >= 7)
                return -1;
            for (int j = 1; j < split.size(); j++)
            {
                g.addEdge(split[j],split[0]); // add edge backwards
            }
        }
    }
    string start;
    cin >> start; // get affected file
    vector<string> ans = g.bfs(start); // dfs on changed file to find affected files
    for (string y: ans)
    {
        cout << y << endl;
    }
    return 0;

}