#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];
long long cost[100001];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, a, b, w;
    cin >> n >> m;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > queue;
    vector<vector<pair<int,int>>> adj(n);
    queue.emplace(0, 0);
    for (int i = 0; i < n; i++) {
        cost[i] = 10e10;
        parent[i] = -1;
    }
    cost[0] = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--;b--;
        adj[a].push_back(make_pair(w, b));
        adj[b].push_back(make_pair(w, a));
    }
    for (int i = 0; i < n-1; i++) {
        pair<long long, int> point = queue.top(); queue.pop();
        if (point.first != cost[point.second]) {
            continue;
        }
        for (pair<long long, int> otherPoint : adj[point.second]) {
            if (point.first + otherPoint.first < cost[otherPoint.second]) {
                parent[otherPoint.second] = point.second;
                cost[otherPoint.second] = point.first + otherPoint.first;
                queue.emplace(cost[otherPoint.second], otherPoint.second);
            }
            
        }
    }
    if (parent[n-1] == -1) {
        cout << "-1" << endl;
    } else {
        int current = n-1;
        vector<int> outputOrder;
        string output = "";
        while (current != 0) {
            outputOrder.push_back(current+1);
            current = parent[current];
        }
        outputOrder.push_back(1);
        reverse(outputOrder.begin(), outputOrder.end());
        for (int num : outputOrder) {
            output += to_string(num);
            output += " ";
        }
        cout << output.substr(0, output.length()-1);
    }
    return 0;
}

