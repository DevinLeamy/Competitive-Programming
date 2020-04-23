#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ll c;
	vector< vector<int> > adj(n);
	vector< vector<ll> > cost(n);
	for (int i = 0; i < n; i++) {
		cin >> c;
		cost[i].push_back(c);
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		cost[i].push_back(c);
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		cost[i].push_back(c);
	}
	int a, b;
	int start = -1;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (adj[a].size() > 2 || adj[b].size() > 2) {
			cout << "-1";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 1) {
			start = i;
			break;
		}
	}
	int val = start;
	int last = -1;
	vector<int> order;
	for  (int i = 0; i < n; i++) {
		order.push_back(val);
		int temp = val;
		val = adj[temp][0];
		if (val == last && adj[temp].size() > 1) {
			val = adj[temp][1];
		}
		last = temp;
	}
	PI best = {-1, -1};
	ll min = LINF;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 2; j++) {
			int cur = i;
			ll price = 0;
			for (int z = 0; z < n; z++) {
				price += cost[order[z]][cur];
				cur = (cur + j)%3;
			}
			if (min > price) {
				min = price;
				best.first = i;
				best.second = j;
			}
		}
	}
	cout << min << "\n";
	vector<int> output(n);
	int cur = best.first;
	for (int i = 0; i < n; i++) {
		output[order[i]] = cur;
		cur = (cur + best.second)%3;
	}
	for (int col : output) {
		cout << col + 1 << " ";
	}
	return 0;
}
