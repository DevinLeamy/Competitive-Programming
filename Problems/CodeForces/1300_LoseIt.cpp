#include <iostream>

using namespace std;

int main()
{
    int N, A;
    cin >> N;
    int seq[6] = {4, 8, 15, 16, 23, 42};
    int record[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if (A == 4)
        {
            record[0]++;
        } else if (A == 8)
        {
            if (record[1] + 1 <= record[0])
            {
                record[1]++;
            }
        } else if (A == 15)
        {
            if (record[2] + 1 <= record[1])
            {
                record[2]++;
            }
        } else if (A == 16)
        {
            if (record[3] + 1 <= record[2])
            {
                record[3]++;
            }
        } else if (A == 23)
        {
            if (record[4] + 1 <= record[3])
            {
                record[4]++;
            }
        } else if (A == 42)
        {
            if (record[5] + 1 <= record[4])
            {
                record[5]++;
            }
        }
    }
    int total = record[5] * 6;
    if (total >= N)
    {
        cout << N % 6 << endl;
    } else {
        cout << N - total << endl;
    }
    return 0;
}
