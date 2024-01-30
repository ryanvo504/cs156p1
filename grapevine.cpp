#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>


using namespace std;

struct node
{
    int tolerance;
    vector<string> adj;
    int dist;
};

class Graph
{
    public: 
        unordered_map<string, node> people;
        int dfs(string x);
        void addEdge(string src, string dest);
        int explore(string x);
        int count;
};


void Graph::addEdge(string src, string dest)
{
    people[src].adj.push_back(dest);
}

int Graph::explore(string x)
{
    int count = 0;
    for (string y: people[x].adj)
    {
        if (people[y].dist == 100000 || (people[y].dist > people[x].dist + 1))
        {
            people[y].dist = people[x].dist + 1;
        }
        if (people[x].tolerance <= people[x].adj.size())
        {
            count++;
        }
        explore(y);
    }
    return count;

}

int Graph::dfs(string x)
{ 
    int count = 0;
    people[x].dist = 0;

    for (string y: people[x].adj)
    {
        if (people[y].dist == 100000 || (people[y].dist > people[x].dist + 1))
        {
            people[y].dist = people[x].dist + 1;
        }
        if (people[x].tolerance <= people[x].adj.size())
        {
            count++;
        }
        count += explore(y);
        
    }
    return count;

}

int main()
{
    Graph g;
    int numPpl, connections, days;
    string temp1, temp2;
    cin >> numPpl >> connections >> days;
    for (int i = 0; i < numPpl; i++)
    {
        node temp;
        cin >> temp1;
        cin >> temp.tolerance;
        temp.dist = 100000;
        g.people[temp1] = temp;
    }
    for (int i = 0; i < connections; i++)
    {
        cin >> temp1 >> temp2;
        g.addEdge(temp1,temp2);
        g.addEdge(temp2,temp1);
        
    }
    string start;
    cin >> start; 
    int finalAns = g.dfs(start);
    cout << finalAns;
    return 0;
}
