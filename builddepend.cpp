#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class File
{
    private:
        string name;
        bool vis;
        int ccnum;
    public:
        File(string x):name(x),vis(false), ccnum(0) {};
        string getName();
        bool returnVis();
        int returnCcnum();
};

int File::returnCcnum()
{
    return ccnum;
}

bool File::returnVis()
{
    return vis;
}


string File::getName()
{
    return name;
}


class edge
{
    private:
        string src;
        string dst;
    public:
        string getSrc();
        string getDst();
        edge(string s, string d) : src(s), dst(d) {} ;
};

string edge::getDst()
{
    return dst;
}
string edge::getSrc()
{
    return src;
}

class Graph
{
    private:
        vector<File> vertices;
        vector<edge> edges;
    public:
        Graph(vector<File> v, vector<edge> e) : vertices(v),edges(e) {};
        void dfs(string x, vector<string> y);

};

void Graph::dfs(string x, vector<string> y)
{
    y.push_back(x);
    for (size_t i = 0; i < edges.size(); i++)
    {

        if (edges[i].getSrc() == x)
        {
            dfs(edges[i].getSrc(),y);
        }
    }
}

int main()
{
    vector<File> files;
    vector<string> ans;
    vector<edge> edgs;
    string line;
    getline(cin, line);
    int n = stoi(line); // read n files for n lines
    for (int i = 0; i < n; i++)
    {
        getline(cin,line);
        size_t pos = line.find(":"); // parse name of file
        File temp = File(line.substr(0,pos - 1));
        if (line.length() > pos + 3)
        {
            line = line.substr(pos + 2); // parse rest of line skipping : and whitespace
            stringstream stream(line);
            while (getline(stream,line, ' ')) // parse each depending file
            {
                edgs.push_back(edge(line,temp.getName()));
            }
            files.push_back(temp); // add file to graph
        }
        else
        {
            files.push_back(temp);
        }
    }
    Graph g = Graph(files,edgs);
    getline(cin, line);
    g.dfs(line,ans);
    
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}