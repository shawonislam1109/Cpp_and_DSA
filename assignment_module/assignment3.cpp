#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int cls;
    string sec;
    int id;

    Student(string name, int cls, string sec, int id)
    {
        this->name = name;
        this->cls = cls;
        this->sec = sec;
        this->id = id;
    }

    void display() const
    {
        cout << name << " " << cls << " " << sec << " " << id << endl;
    }
};

int main()
{
    int N;
    cin >> N;

    Student **students = new Student *[N];
    for (int i = 0; i < N; i++)
    {
        string name;
        int cls;
        string sec;
        int id;

        cin >> name >> cls >> sec >> id;
        students[i] = new Student(name, cls, sec, id);
    }

    for (int i = 0, j = N - 1; i < j; i++, j--)
    {
        swap(students[i]->sec, students[j]->sec);
    }

    for (int i = 0; i < N; i++)
    {
        students[i]->display();
    }

    for (int i = 0; i < N; i++)
    {
        delete students[i];
    }
    delete[] students;

    return 0;
}
