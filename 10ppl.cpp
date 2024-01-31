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
        vector<vector<char>> map;
        vector<vector<bool>> vis;
        void dfs(int x1, int y1, int x2, int y2);
        void explore(string x);
        string type(char x);
};

string Graph::type(char x)
{
    if (x == '0')
        return "binary";
    else if (x == '1')
        return "decimal";
    else
        return "neither";

}
void Graph::dfs(int x1, int y1, int x2, int y2)
{
    if (type(map[x1 - 1][y1 - 1]) == type(map[x2 - 1][y2 - 1]))
    {
        cout << "neither" << endl;
    }
    else
    {
        vis[x1-1][y1-1] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    Graph g;
    int r, c;
    cin >> r >> c;
    cin.ignore();
    g.map.resize(r);
    for (int i = 0; i < r; i++)
    {
        g.map.at(i).resize(c);
        string line;
        getline(cin, line);
        for (int j = 0; j < c; j++)
        {
            g.map[i].push_back(line.at(j));
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        g.dfs(r1,c1,r2,c2);
    }
    return 0;

    

}