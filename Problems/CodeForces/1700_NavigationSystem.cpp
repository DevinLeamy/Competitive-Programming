#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<vector<int>> back(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v);
		back[v].pb(u);
	}
	int k; cin >> k;
	vector<int> iter(k);
	for (int i = 0; i < k; i++) {
		cin >> iter[i]; iter[i]--;
	}
	
	vector<int> dist(n, INF);
	vector<int> cnt_best(n);
	
	queue<vector<int>> queue;
	queue.push({iter[k-1], -1, 0});
	
	while (!queue.empty()) {
		int cur = queue.front()[0];
		int lst = queue.front()[1];
		int dst = queue.front()[2];
		queue.pop();
		if (dist[cur] < dst) continue;
		
		if (dist[cur] == INF) {
			dist[cur] = dst;
			cnt_best[cur]++;
		} else if (dist[cur] == dst) {
			cnt_best[cur]++;
			continue;
		} else {
			dist[cur] = dst;
			cnt_best[cur] = 1;
		}
		
		for (int val : back[cur]) {
			if (val == lst) continue;
			queue.push({val, cur, dst + 1});
		}
	}
	int cnt_min = 0;
	int cnt_max = 0;
	int last = -1;
	for (int loc : iter) {
		if (last != -1) {
			if (dist[loc] > dist[last] - 1) {
				cnt_max++;
				cnt_min++;
			} else {
				if (cnt_best[last] > 1) {
					cnt_max++;
				}
			}
		}
		last = loc;
	}
	
	printf("%i %i", cnt_min, cnt_max);
	return 0;
}
