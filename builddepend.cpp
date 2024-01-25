#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Makes
{
    private:
        string name;
        vector<string> depends;
    public:
        Makes(string x):name(x) {};
        void addDepend(string x);
};

void Makes::addDepend(string x)
{
    depends.push_back(x);
}

int main()
{
    vector<Makes> m;
    string line;
    getline(cin, line);
    int n = stoi(line);
    for (int i = 0; i < n; i++)
    {
        getline(cin,line);
        size_t pos = line.find(":");
        Makes temp = Makes(line.substr(0,pos - 1));
        line = line.substr(pos + 1);
        stringstream stream(line);
        while (getline(stream,line, ' '))
        {
            temp.addDepend(line);
        }
        m.push_back(temp);

    }
    return 0;
}