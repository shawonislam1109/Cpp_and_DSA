#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Students
{
public:
    string name;
    int roll;
    int marks;

    Students(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class Cmp
{
public:
    bool operator()(Students l, Students r)
    {
        if (l.marks < r.marks)
            return true;
        else if (l.marks > r.marks)
            return false;
        else
            return l.roll > r.roll;
    }
};

int main()
{
    int n;
    cin >> n;

    priority_queue<Students, vector<Students>, Cmp> pq;

    for (int i = 0; i < n; ++i)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Students obj(name, roll, marks);
        pq.push(obj);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int command;
        cin >> command;

        if (command == 1)
        {
            if (!pq.empty())
            {
                Students top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (command == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                {
                    Students top = pq.top();
                    cout << top.name << " " << top.roll << " " << top.marks << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (command == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Students obj(name, roll, marks);
            pq.push(obj);

            Students top = pq.top();
            cout << top.name << " " << top.roll << " " << top.marks << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }

    return 0;
}
