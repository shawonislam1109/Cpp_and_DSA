#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    char name[200];
    int age;

    Person(const char *name, int age)
    {
        strcpy(this->name, name);
        this->age = age;
    }
};

Person *fun()
{

    Person *Jamal = new Person("Jamal hessian", 29);
    return Jamal;
}

int main()
{
    Person *jamal = new Person("Anisul Karim", 89);

    Person *kamal = fun();
    cout << kamal->name << " " << kamal->age;
    return 0;

    delete kamal;
}