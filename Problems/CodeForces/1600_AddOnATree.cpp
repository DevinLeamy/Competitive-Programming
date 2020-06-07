#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector <vector<int> > adj;
    int N, A, B;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        adj.emplace_back(vector<int>());
    }
    for (int i = 0; i < N-1; i++)
    {
        cin >> A >> B;
        A--;
        B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    bool good = true;
    for (int i = 0; i < N; i++)
    {
        if (adj[i].size() == 2)
        {
            good = false;
            break;
        }
    }
    if (good)
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

