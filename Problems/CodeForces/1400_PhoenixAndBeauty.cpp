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
	int t; cin >> t;
	loop(t) {
		int n, k, a; cin >> n >> k;
		vector<int> vals;
		set<int> unique;
		for (int i = 0; i < n; i++) { cin >> a; vals.pb(a); unique.insert(a); }
		if (unique.size() > k) { cout << -1 << endl; continue; }
		string output = "";
		vector<int> cycle;
		for (auto iter = unique.begin(); iter != unique.end(); iter++) { cycle.pb(*iter); }
		while (cycle.size() < k) {
			cycle.pb(1);
		}
		int index = 0;
		int len = 0;
		for (int i = 0; i < n; i++) {
			if (cycle[index] != vals[i]) { i--; }
			output += to_string(cycle[index]) + " ";
			index = (index + 1) % cycle.size();
			len++;
		}
		cout << len << "\n" << output << "\n";
	}
	return 0;
}
