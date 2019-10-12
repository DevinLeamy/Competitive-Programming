#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    bool rooms[10];
    for (int i = 0; i < 10; i++)
    {
        rooms[i] = false;
    }
    string events;
    cin >> events;
    for (int i = 0; i < N; i++)
    {
        char E = events[i];
        if (E == 'L')
        {
            for (int j = 0; j < 10; j++)
            {
                if (!rooms[j])
                {
                    rooms[j] = true;
                    break;
                }
            }
        } else if (E == 'R')
        {
            for (int j = 9; j >= 0; j--)
            {
                if (!rooms[j])
                {
                    rooms[j] = true;
                    break;
                }
            }
        } else {
            int nowEmpty = (int)E - 48;
            rooms[nowEmpty] = false;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (rooms[i])
        {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}
