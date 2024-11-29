#include <bits/stdc++.h>
using namespace std;

// -> STUDENT CLASS
class Student
{
public:
    string name;
    int age;

    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << this->name << " " << this->age;
    }
};

int main()
{

    int N;
    cin >> N;
    cin.ignore();

    Student *students[N];

    for (int i = 0; i < N; i++)
    {
        string name;
        int age;

        getline(cin, name);
        cin >> age;
        cin.ignore();
        students[i] = new Student(name, age);
    }

    Student *max = students[0];
    Student *min = students[0];

    for (int i = 1; i < 3; i++)
    {
        if (students[i]->age < max->age)
        {
            max = students[i];
        }

        if (students[i]->age > min->age)
        {
            min = students[i];
        }
    }

    cout << "Max: ";
    max->display();
    cout << endl;

    cout << "Min: ";
    min->display();
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        delete students[i];
    }

    return 0;
}
