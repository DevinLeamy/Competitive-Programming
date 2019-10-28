#include <iostream>
#include <vector>

using namespace std;

int INF = 10e8 + 1;
long long dp[100001];
int main() {
    int N, W, w, v;
    scanf("%i%i", &N, &W);
    vector< pair<int, int> > items;
    int maxValue = 0;
    for (int i = 0; i < N; i++) {
        scanf("%i%i", &w, &v);
        maxValue += v;
        items.push_back({w, v});
    }
    for (int i = 0; i <= maxValue; i++) {dp[i] = INF;}
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        v = items[i].second;
        for (int j = maxValue; j >= v; j--) {
            dp[j] = min(dp[j], (dp[j-v] + items[i].first > W)? INF : dp[j-v] + items[i].first);
        }
    }
    long long output = -1;
    for (int i = 0; i <= maxValue; i++) {
        if (dp[i] <= W) {
            output = max(output, (long long)i);
        }
    }
    cout << output << endl;
    return 0;
}
