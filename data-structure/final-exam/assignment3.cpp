#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int x;
    cin >> x;
    cin.ignore();

    while (x--)
    {
        string sentences;
        getline(cin, sentences);

        map<string, int> wordCount;
        stringstream stream(sentences);

        string singleWord;
        string maxWord;
        int maxCount = 0;

        while (stream >> singleWord)
        {
            wordCount[singleWord]++;
            if (wordCount[singleWord] > maxCount)
            {
                maxCount = wordCount[singleWord];
                maxWord = singleWord;
            }
        }

        cout << maxWord << " " << maxCount << endl;
    }

    return 0;
}
