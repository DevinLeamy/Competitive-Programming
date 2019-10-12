#include <iostream>
#include <vector>

using namespace std;


string getLongestString(string a, string b)
{
    if (a.length() >= b.length())
    {
        return a;
    }
    return b;
}
string getLCS(string string1, string string2)
{
    string dp[string1.length()+1][string2.length()+1];
    for (int i = 1; i <= string1.length(); i++)
    {
        for (int j = 1; j <= string2.length(); j++)
        {
            if (string1.at(i-1) == string2.at(j-1))
            {
                dp[i][j] = getLongestString(dp[i-1][j-1], dp[i][j-1]) + string1.at(i-1);
            } else {
                dp[i][j] = getLongestString(dp[i-1][j-1], dp[i][j-1]);
            }
        }
    }
    return dp[string1.length()][string2.length()];
}

int main()
{
    string string1, string2;
    cin >> string1 >> string2;
    string output = getLCS(string1, string2);
    cout << output << endl;

    return 0;
}