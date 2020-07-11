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
	vector<int> vals(n);
	vector<vector<int>> pre;
	pre.pb(vector<int>(101));
	for (int i = 0; i < n; i++) { cin >> vals[i]; }
	for (int i = 0; i < n; i++) {
		int val = vals[i];
		pre.pb(vector<int>(101));
		pre[i + 1][val]++;
		for (int j = 0; j <= 100; j++) {
			pre[i + 1][j] += pre[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int val = vals[i];
		int temp = m;
		for (int j = 0; j <= 100; j++) {
			temp -= pre[i][j] * j;
		}
		int count = 0;
		for (int j = 100; j >= 0; j--) {
			if (temp >= val) {
				break;
			}
			int diff = val - temp;
			int max = min(pre[i][j], diff / j + ((diff % j == 0)? 0 : 1));
			count += max;
			temp += max * j;
		}
		cout << count << " ";
	}
	return 0;
}
