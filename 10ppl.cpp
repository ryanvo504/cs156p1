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
        int adj[1000][1000];
        bool vis[1000][1000];
        unordered_map<string, int> post;
        unordered_map<string, int> pre;
        vector<string> bfs(string x);
        void explore(string x);
        void addEdge(string src, string dest);
};

int main()
{
    ios_base::sync_with_stdio(false);
    int r, c;
    cin >> r >> c;

    

}