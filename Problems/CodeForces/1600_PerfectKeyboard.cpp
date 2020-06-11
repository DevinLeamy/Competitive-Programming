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

string alp = "abcdefghijklmnopqrstuvwxyz";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		string s, ans = ""; cin >> s;
		if (s.length() == 1) { cout << "YES\n" << alp << "\n"; continue; }
		vector<bool> taken(26);
		vector<set<int>> adj(26);
		bool valid = true;
		int first = -1;
		for (int i = 0; i < s.length() - 1; i++) {
			int a = s[i] - 'a';
			int b = s[i+1] - 'a';
			adj[a].insert(b);
			adj[b].insert(a);
		}
		for (int i = 0; i < 26; i++) {
			if (adj[i].size() == 1) { first = i; }
			else if (adj[i].size() > 2) { valid = false; }
		}
		if (first == -1 || !valid) { cout << "NO" << "\n"; continue; }
		queue<PI> vals; vals.push({first, -1});
		while(!vals.empty()) {
			PI val = vals.front(); vals.pop();
			int index = val.first;
			int last = val.second;
			if (taken[index]) { valid = false; break; }
			taken[index] = true;
			ans += alp[index];
			if (last != *next(adj[index].begin(), 0)) {
				vals.push({*next(adj[index].begin(), 0), index});
			} else if (adj[index].size() > 1){
				vals.push({*next(adj[index].begin(), 1), index});
			}
		}
		for (int i = 0; i < 26; i++) {
			if (!taken[i]) { ans += alp[i]; }
		}
		if (valid) { cout << "YES\n" << ans << "\n"; }
		else { cout << "NO" << "\n"; }
	}
	return 0;
}
