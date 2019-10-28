#include <iostream>
#include <vector>

using namespace std;

int INF = 10e8 + 1;
long long dp[(int)10e5+1];
int main() {
    int N, W, w, v;
    scanf("%i%i", &N, &W);
    vector< pair<int, int> > items;
    for (int i = 0; i < N; i++) {
        scanf("%i%i", &w, &v);
        items.push_back({w, v});
    }
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= items[i].first; j--) {
            dp[j] = max(max(dp[j-1], dp[j]), dp[j-items[i].first] + items[i].second);
        }
    }
    cout << dp[W] << endl;
    return 0;
}
