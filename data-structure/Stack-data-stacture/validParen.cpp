#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass
{
public:
    vector<string> v;

    void push(string s)
    {
        v.push_back(s);
    }
    int size()
    {
        return v.size();
    }
    string top()
    {
        return v.back();
    }
};

int main()
{
    MyClass s1;
    MyClass s2;

    string s = ")(";

    for (char c : s)
    {
        if (c == '(')
        {
            s1.push("(");
        }
        if (s1.top() == "(" && c == ')' && !s1.top().empty())
        {
            s2.push(")");
        }
    }

    if (s1.size() <= s2.size())
    {
        cout << s1.size() + s1.size();
    }
    else
    {
        cout << s2.size() + s2.size();
    }

    return 0;
}
