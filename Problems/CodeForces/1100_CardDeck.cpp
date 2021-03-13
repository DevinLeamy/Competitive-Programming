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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<int> vals(n);
		for (int i = 0; i < n; i++)
			cin >> vals[i];
		
		vector<int> res;
		int cur = n;
		vector<int> taken(n + 1);
		for (int i = n - 1; i >= 0; i--) {
			vector<int> add;
			while (vals[i] != cur) {
				add.pb(vals[i]);
				taken[vals[i]] = true;
				i--;
			}
			add.pb(vals[i]);
			taken[vals[i]] = true;
			while (taken[cur])
				cur--;
			
			for (int j = (int) add.size() - 1; j >= 0; j--)
				res.pb(add[j]);
		}
		for (int val : res)
			cout << val << " ";
		cout << endl;
	}
	return 0;
}
