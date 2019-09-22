#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    long long N, K, day, boost, cost, totalCost = 0;
    cin >> N >> K;
    long long eachDay[N], costs[N];
    priority_queue <long long, vector<long long>, greater<>> queue;
    bool good = true;
    for (int i = 0; i < N; i++)
    {
        cin >> day;
        eachDay[i] = day;
    }
    cin >> boost;
    for (int i = 0; i < N; i++)
    {
        cin >> cost;
        costs[i] = cost;
    }
    for (int i = 0; i < N; i++)
    {
        queue.push(costs[i]);
        while (eachDay[i] > K && !queue.empty())
        {
            totalCost += queue.top();
            queue.pop();
            K += boost;
        }
        if (eachDay[i] > K)
        {
            good = false;
            break;
        }
    }
    if (good)
    {
        cout << totalCost << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

