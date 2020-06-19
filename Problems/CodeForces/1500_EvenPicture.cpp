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
	int n; cin >> n;
	PI left = {1, 1};
	vector<PI> ans;
	ans.pb({0, 0});
	ans.pb({1, 0});
	ans.pb({0, 1});
	ans.pb({-1, 0});
	ans.pb({0, -1});
	ans.pb({1, 1});
	ans.pb({-1, -1});
	int cur = 1;
	while(cur != n) {
		ans.pb({left.first+1, left.second});
		ans.pb({left.first, left.second+1});
		ans.pb({left.first+1, left.second+1});
		left.first++;
		left.second++;
		cur++;
	}
	cout << ans.size() << endl;
	for (PI val: ans) {
		cout << val.first << " " << val.second << endl;
	}
	
	return 0;
}
