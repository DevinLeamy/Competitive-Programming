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
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> n;
		vector<int> vals(n+1);
		vector<int> count(n+1);
		int maxa = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			vals[a]++;
			if (vals[a] == 1) {
				count[1]++;
			} else {
				count[vals[a] - 1]--;
				count[vals[a]]++;
			}
			maxa = max(maxa, vals[a]);
		}
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			if (vals[i] == maxa) {
				ans++;
			}
		}
		cout << (n - maxa - ans + 1)/(maxa - 1) << endl;
	}
	return 0;
}
