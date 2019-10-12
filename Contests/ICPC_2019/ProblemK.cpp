#include <iostream>

using namespace std;

int main()
{
    string e;
    cin >> e;
    string current;
    long count = 0;
    for (int i = 0; i < e.length(); i++)
    {
        current = e[i];

        for (int j = i+1; j < e.length(); j++)
        {
            char character = e[j];
            if (character == current[0])
            {
                break;
            } else if (current.find(character) == string::npos)
            {
                count++;
            }
            current += character;
        }
    }
    cout << count << endl;
    return 0;
}