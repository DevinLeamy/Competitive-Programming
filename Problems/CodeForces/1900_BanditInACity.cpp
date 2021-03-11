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

vector<ll> dfs(int cur, vector<vector<int> > &adj, int n, vector<ll> &people) {
	vector<ll> res = { 0, 0, 0 }; // max, room, nodes
	if (adj[cur].size() == 0)
		return { people[cur], 0, 1 };
	
	vector<pair<ll, ll > > nodes; // max, room
	ll max = 0;
	ll room = 0;
	ll node_total = 0;
	for (int node : adj[cur]) {
		vector<ll> node_res = dfs(node, adj, n, people);
		ll max_people = node_res[0];
		ll room_til_inc = node_res[1];
		ll node_cnt = node_res[2];
		
		room += room_til_inc;
		node_total += node_cnt;
		max = std::max(max, max_people);
		nodes.pb(make_pair(max_people, node_cnt));
	}

	for (PL val : nodes) {
		ll diff = max - val.first;
		room += diff * val.second;
	}
	ll take = min(room, people[cur]);
	room -= take;
	
	ll rem = people[cur] - take;
	ll inc = floor((double)rem / (double)node_total) + ((rem % node_total == 0)? 0 : 1);
	ll new_room = room;
	if (rem % node_total != 0)
		new_room += node_total - (rem % node_total);
	
	res[0] = max + inc;
	res[1] = new_room;
	res[2] = node_total;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int p; cin >> p;
		adj[p - 1].pb(i + 1);
	}
	vector<ll> people(n);
	for (int i = 0; i < n; i++)
		cin >> people[i];
	
	vector<ll> res = dfs(0, adj, n, people);
	cout << res[0] << endl;
	return 0;
}
