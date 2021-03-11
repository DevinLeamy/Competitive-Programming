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

int ans[101][101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<int> row(n), col(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = 0;
		
		for (int i = 0; i < n; i++) {
			ans[i][i] = 1;
			ans[i][i - 1] = 1;
		}
		ans[0][n-1] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
