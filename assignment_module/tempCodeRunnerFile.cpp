#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int cls;
    string sec;
    int id;
    int math_marks;
    int eng_marks;

    Student(string name, int cls, string sec, int id, int math_marks, int eng_marks)
    {
        this->name = name;
        this->cls = cls;
        this->sec = sec;
        this->id = id;
        this->math_marks = math_marks;
        this->eng_marks = eng_marks;
    }

    void display() const
    {
        cout << name << " " << cls << " " << sec << " " << id << " " << math_marks << " " << eng_marks << endl;
    }
};

bool compare(const Student *a, const Student *b)
{
    if (a->eng_marks != b->eng_marks)
        return a->eng_marks > b->eng_marks;
    if (a->math_marks != b->math_marks)
        return a->math_marks > b->math_marks;
    return a->id < b->id;
}

int main()
{
    int N;
    cin >> N;

    Student *students[N];
    for (int i = 0; i < N; i++)
    {
        string name;
        int cls;
        string sec;
        int id;
        int math_marks;
        int eng_marks;

        cin >> name >> cls >> sec >> id >> math_marks >> eng_marks;
        students[i] = new Student(name, cls, sec, id, math_marks, eng_marks);
    }

    sort(students, students + N, compare);

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
