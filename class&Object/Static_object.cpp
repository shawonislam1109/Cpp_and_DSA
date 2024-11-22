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
    Person Jamal("Jamal hessian", 29);
    Person *p = &Jamal;
    return p;
}

int main()
{

    // Create a Person object
    Person karim("Anisul Karim", 89);

    // Use the fun function
    Person *jamal = fun(); // Store the returned Person object

    // Output details
    cout << "Karim: " << karim.name << ", Age: " << karim.age << "\n";
    cout << "Jamal: " << jamal->name << ", Age: " << jamal->age << "\n";

    return 0;
}