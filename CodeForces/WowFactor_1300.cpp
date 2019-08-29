#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;
    long long count[S.length()];
    count[0] = 0;
    char pre = S[0];
    long long wows = 0;
    for (int i = 1; i < S.length(); i++)
    {
        char current = S[i];
        if (pre == 'v' && pre == current)
        {
            count[i] = count[i-1] + 1;
        } else {
            pre = current;
            count[i] = count[i - 1];
        }
    }
    for (int i = 0; i < S.length(); i++)
    {
        char current = S[i];
        if (current == 'o')
        {
            wows += count[i] * (count[S.length() - 1] - count[i]);
        }
    }
    cout << wows << endl;
    
    return 0;
}
