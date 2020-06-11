#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<PI> topicSorted;
	vector<int> topic;
	int a, b, t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		topicSorted.pb({t, i}); //Topic and node
		topic.pb(t);
	}
	sort(topicSorted.begin(), topicSorted.end());
	for (int i = 0; i < n; i++) {
		vector<bool> covered(topicSorted[i].first-1);
		for (int node : adj[topicSorted[i].second]) {
			if (topic[node] == topicSorted[i].first) {
				cout << "-1" << endl;
				return 0;
			} else if (topicSorted[i].first != 1){
				if (topic[node] < topicSorted[i].first) {
					covered[topic[node]-1] = true;
				}
			}
		}
		if (topicSorted[i].first != 1) {
			for (bool val: covered) {
				if (!val) {
					cout << "-1" << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << topicSorted[i].second + 1 << " ";
	}
	return 0;
}
