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
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, x; cin >> n >> x; x--;
		vector<vector<int>> adj(n);
		int a, b;
		for (int i = 0; i < n-1; i++) {
			cin >> a >> b;
			a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		if (adj[x].size() == 1 || adj[x].size() == 0) {
			cout << "Ayush" << endl;
			continue;
		}
		int count = 0;
		queue<PI> q; //current, last
		q.push({x, -1});
		while(!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int node : adj[cur.first]) {
				if (node != cur.second) {
					count++;
					q.push({node, cur.first});
				}
			}
		}
		if (count % 2 == 1) { cout << "Ayush" << endl; }
		else { cout << "Ashish" << endl; }
	}
	return 0;
}
