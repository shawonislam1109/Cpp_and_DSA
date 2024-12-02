#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int age;
    int marks;

    Student(string name, int age, int marks)
    {
        this->name = name;
        this->age = age;
        this->marks = marks;
    }

    void display()
    {
        cout << this->name << " " << this->age << " " << this->marks << endl;
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
        int marks;
        getline(cin, name);
        cin >> age;
        cin >> marks;
        cin.ignore();
        students[i] = new Student(name, age, marks);
    }

    // Sort Method  using
    sort(students, students + N, [](Student *a, Student *b)
         {
             if (a->marks == b->marks)
             {
                 return a->age > b->age;
             }
             else
             {
                 return a->marks > b->marks;
             } });

    // manual sorting
    // for (int i = 0; i < N - 1; i++)
    // {
    //     for (int j = i + 1; j < N; j++)
    //     {
    //         if (students[i]->marks = students[j]->marks)
    //         {
    //             if (students[i]->age > students[j]->age)
    //             {
    //                 swap(students[i], students[j]);
    //             }
    //         }
    //         else if (students[i]->marks > students[j]->marks)
    //         {
    //             swap(students[i], students[j]);
    //         }
    //     }
    // }

    for (int i = 0; i < N; i++)
    {
        students[i]->display();
    }

    for (int i = 0; i < N; i++)
    {
        delete students[i];
    }

    return 0;
}
