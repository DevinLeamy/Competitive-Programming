#include <iostream>

using namespace std;
int main()
{
    string time;
    cin >> time;
    bool has = false;
    int count = 0;
    char C;
    for (int i = 1; i < time.size(); i++)
    {
        C = time[i];
        if (C == '1')
        {
            has = true;
        }
        if (i % 2 == 1)
        {
            count++;
        }
    }
    if (time.size() % 2 == 1 && has)
    {
        count++;
    }
    cout << count;
    return 0;
}
