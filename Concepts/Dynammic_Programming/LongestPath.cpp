#include <iostream>
#include <vector>
using namespace std;

int dp[100002];
vector < vector<int> > adj(100002);
void dfs(int);
int main() {
    ios_base::sync_with_stdio(0);
    int N, M, x, y;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) { adj[0].push_back(i);}
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 0; i <= N; i++) { dp[i] = -1; }
    dfs(0);
    cout << (dp[0] - 1) << endl;
    return 0;
}
void dfs(int node) {
    if (adj[node].size() == 0) { dp[node] = 0; }
    else {
        int maximum = -1;
        for (int children : adj[node]) {
            if (dp[children] == -1) {
                dfs(children);
            }
            maximum = max(dp[children] + 1, maximum);
        }
        dp[node] = maximum;
    }
    
}


// 1 2 3 4 5
// 1 3 6 10 15 dp[i] = a[i] + dp[i-1] <- pervious state

/*
    dp[i] = the longest path in the graph from the i'th node
    dp[i] (let i == the i'th node) dp[i] = dp[i+1] (let i+1 == the next node you are going to visit) + 1
    
 */
