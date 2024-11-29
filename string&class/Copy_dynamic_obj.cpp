#include <bits/stdc++.h>
using namespace std;

class Cricketer
{
public:
    string name;
    int jersey_number;

    Cricketer(string name, int jersey_number)
    {
        this->jersey_number = jersey_number;
        this->name = name;
    }
};

int main()
{

    Cricketer *Virat = new Cricketer("Virat", 18);
    Cricketer *Dhoni = new Cricketer("Dhoni", 7);
    Dhoni = Virat;

    delete Dhoni;

    cout << Virat->name << " " << Virat->jersey_number << endl;
    return 0;
}