#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    char name[200];
    int age;
    int roll;
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    Student students1[n];

    for (int i = 0; i < n; i++)
    {

        cin.getline(students1[i].name, 200);
        cin >> students1[i].age;
        cin >> students1[i].roll;
        cin.ignore();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students1[i].name << endl;
        cout << "Age: " << students1[i].age << endl;
        cout << "Roll Number: " << students1[i].roll << endl;
        cout << endl;
    }

    return 0;
}
