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
};

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
        m.push_back(Makes(line.substr(0,pos - 1)));
        line = line.substr(pos + 1);
        stringstream stream(line);
        while (getline(stream,line, ' '))
        {
            
        }

    }
    return 0;
}