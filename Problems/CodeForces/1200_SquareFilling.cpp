#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int matrix[50][50];
    int otherMatrix[50][50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            otherMatrix[i][j] = 0;
        }
    }
    vector<string> output;
    bool works = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (matrix[i][j] == 1)
            {
                if (matrix[i+1][j] == 1 && matrix[i][j + 1] == 1 && matrix[i+1][j+1] == 1)
                {
                    otherMatrix[i][j] = 1;
                    otherMatrix[i+1][j] = 1;
                    otherMatrix[i][j+1] = 1;
                    otherMatrix[i+1][j+1] = 1;
                    output.push_back(to_string(i + 1) + " " + to_string(j + 1));
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != otherMatrix[i][j])
            {
                works = false;
            }
        }
    }
    if (!works)
    {
        cout << "-1";
    } else {
        cout << output.size() << endl;
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << endl;
        }
    }
    return 0;
}
