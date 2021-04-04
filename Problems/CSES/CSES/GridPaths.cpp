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

bool trap[1005][1005];
ll cnts[1005][1005];
ll mod = 1000000007ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			trap[i][j] = s[j] == '*';
			cnts[i][j] = 0;
		}
	}
	if (trap[0][0]) {
		cout << 0 << "\n";
		return 0;
	}
	cnts[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0 && j == 0) || trap[i][j])
				continue;
			ll sum = 0;
			if (i != 0)
				sum += cnts[i - 1][j];
			if (j != 0)
				sum += cnts[i][j - 1];
			sum %= mod;
			cnts[i][j] = sum;
		}
	}
	cout << cnts[n - 1][n - 1] << "\n";
	return 0;
}
