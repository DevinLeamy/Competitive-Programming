#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    long long S, I, E;
    for (int i = 0; i < T; i++)
    {
        cin >> S >> I >> E;
        if (S <= I)
        {
            E -= (I - S) + 1;
            S += (I - S) + 1;
            if (E < 0)
            {
                cout << 0 << endl;
                continue;
            }
        }
        long long D = S - I;
        if (E == 0)
        {
            cout << 1 << endl;
        } else if (D > E)
        {
            cout << E + 1 << endl;
        } else {
            long long Z = ((D - E) * -1)/2;
            cout << E - Z << endl;
        }
    }
    
    
    return 0;
}
