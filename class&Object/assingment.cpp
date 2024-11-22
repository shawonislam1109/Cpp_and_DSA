#include <bits/stdc++.h>
using namespace std;

// PROBLEM NUMBER 3
// int main()
// {
//     string line;
//     while (getline(cin, line))
//     {
//         line.erase(remove(line.begin(), line.end(), ' '), line.end());
//         sort(line.begin(), line.end());
//         cout << line << endl;
//     }

//     return
// }

// PROBLEM NUMBER 4

class Student
{
public:
    int ID;
    string name;
    string section;
    int marks;
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Student students[3];

        for (int i = 0; i < 3; i++)
        {
            cin >> students[i].ID >> students[i].name >> students[i].section >> students[i].marks;
        }
        Student bestStudent = students[0];
        for (int i = 1; i < 3; i++)
        {
            if (students[i].marks > bestStudent.marks ||
                (students[i].marks == bestStudent.marks && students[i].ID < bestStudent.ID))
            {
                bestStudent = students[i];
            }
        }

        cout << bestStudent.ID << " "
             << bestStudent.name << " "
             << bestStudent.section << " "
             << bestStudent.marks << endl;
    }

    return 0;
}
