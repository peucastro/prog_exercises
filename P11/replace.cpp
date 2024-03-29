#include <iostream>
#include <map>
using namespace std;

void replace(const map<char, char> &r, string &s)
{
    for (char &c : s)
    {
        auto itr = r.find(c);
        if (itr != r.end())
            c = itr->second;
    }
}

int main()
{
    {
        string s = "C / C++ @ LEIC";
        replace({{'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
        cout << s << '\n';
    }
    {
        string s = "C / C++ @ LEIC";
        replace({}, s);
        cout << s << '\n';
    }
    {
        string s = "A B C D E F";
        replace({{' ', '_'}}, s);
        cout << s << '\n';
    }
    {
        string s = "A B C D E F";
        replace({{'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s);
        cout << s << '\n';
    }
    return 0;
}
