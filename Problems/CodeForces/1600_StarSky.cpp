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
	int n, q, c; cin >> n >> q >> c;
	vector<vector<vector<int> > > stars(101, vector<vector<int> >(101, vector<int>()));
	vector<vector<vector<int> > > presum(c + 1, vector<vector<int> >(102, vector<int>(102)));
	for (int i = 0; i < n; i++) {
		int x, y, s; cin >> x >> y >> s;
		--x; --y;
		stars[x][y].pb(s);
	}
	int mod = c + 1;
	for (int j = 0; j < 101; j++) {
		for (int k = 0; k < 101; k++) {
			for (int i = 0; i <= c; i++) {
				presum[i][j][k + 1] = presum[i][j][k];
				int add = 0;
				for (int val : stars[j][k]) {
					add += (val + i) % mod;
				}
				presum[i][j][k+1] += add;
			}
		}
	}
	
	for (int i = 0; i < q; i++) {
		ll t; int x1, x2, y1, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		--x1; --x2; --y1; --y2;
		int time = t % mod;
		ll sum = 0;
		for (int j = x1; j <= x2; j++) {
			sum += presum[time][j][y2 + 1] - presum[time][j][y1];
		}
		cout << sum << endl;
	}

	return 0;
}
