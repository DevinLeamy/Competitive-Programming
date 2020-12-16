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
		int n, m, cnt = 0; cin >> n >> m;
		vector<vector<int>> tree;
		string line;
		for (int i = 0; i < n; i++) {
			cin >> line;
			tree.pb(vector<int>(m));
			for (int j = 0; j < m; j++) {
				tree[i][j] = (line[j] == '*');
				cnt += (line[j] == '*')? 1 : 0;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!tree[i][j]) continue;
				int left = 0;
				int right = 0;
				int lp = j;
				int rp = j;
				while (lp - 1 >= 0 && tree[i][lp - 1]) {
					left++;
					lp--;
				}
				while (rp + 1 < m && tree[i][rp + 1]) {
					right++;
					rp++;
				}
				int base = min(left, right) + 1;
				int trees = min(base, tree[i-1][j] + 1);
				tree[i][j] = trees;
				cnt += trees - 1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
