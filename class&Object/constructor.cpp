#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    char name[200];
    int age;
    double height;

    Person(const char *name, int age, double height)
    {
        strcpy(this->name, name);
        this->age = age;
        this->height = height;
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    Person *persons[n];

    for (int i = 0; i < n; i++)
    {
        double height;
        char name[200];
        int age;

        cin.getline(name, 200);
        cin >> age;
        cin >> height;
        cin.ignore();

        persons[i] = new Person(name, age, height);
    };

    for (int i = 0; i < n; i++)
    {
        cout << "Person " << i + 1 << endl;
        cout << "Name: " << persons[i]->name << endl;
        cout << "Age: " << persons[i]->age << endl;
        cout << "Height: " << persons[i]->height << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete persons[i];
    }

    return 0;
}