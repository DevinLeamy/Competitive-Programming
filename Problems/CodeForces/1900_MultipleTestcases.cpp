#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, k; cin >> n >> k;
	vector<int> vals(n);
	vector<int> cnts(k);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
	sort(vals.begin(), vals.end());
		
	for (int i = 0; i < k; i++)
		cin >> cnts[i];
	
	int min = 0;
	for (int i = 0; i < k; i++) {
		int cnt = (int) (lower_bound(vals.begin(), vals.end(), i + 1) - vals.begin());
		cnt = n - cnt;
		int req = cnt / cnts[i] + ((cnt % cnts[i] == 0)? 0 : 1);
		if (req > min) {
			min = req;
		}
	}
	
	// Test cases required
	cout << min << endl;
	
	vector<vector<int>> ans(min, vector<int>());
	reverse(vals.begin(), vals.end());
	int cur = 0;
	for (int val : vals) {
		ans[cur].pb(val);
		cur = (cur + 1) % min;
	}
	for (vector<int> val : ans) {
		cout << val.size() << " ";
		for (int num : val)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}
