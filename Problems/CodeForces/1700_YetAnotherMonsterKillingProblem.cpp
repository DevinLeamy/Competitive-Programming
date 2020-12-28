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
		vector<ll> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		int m; cin >> m;
		vector<ll> sth(n+1, -1);
		for (int i = 0; i < m; i++) {
			ll p, s; cin >> p >> s;
			sth[s] = max(p, sth[s]);
		}
			
		for (int i = n-1; i >= 0; i--)
			sth[i] = max(sth[i], sth[i+1]);
		
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			int cur = 1;
			ll largest = vals[i];
			while (i < n && sth[cur] >= vals[i] && sth[cur] >= largest) {
				largest = max(largest, vals[i]);
				cur++;
				i++;
			}
			i--;
			if (cur == 1) {
				flag = true;
				break;
			}
			cnt++;
		}
		if (flag) printf("-1\n");
		else printf("%i\n", cnt);
	}
	return 0;
}
