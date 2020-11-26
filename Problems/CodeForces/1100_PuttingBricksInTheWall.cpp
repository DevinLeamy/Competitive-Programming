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
		int n;
		cin >> n;
		int grid[n][n];
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			grid[i][j] = c-'0';
		    }
		}
		for (int i = 0; i <= 1; i++) {
		    vector<pair<int,int>> v;
		    if (grid[1][0] != i) v.push_back({1,0});
		    if (grid[0][1] != i) v.push_back({0,1});
		    if (grid[n-1][n-2] != 1-i) v.push_back({n-1,n-2});
		    if (grid[n-2][n-1] != 1-i) v.push_back({n-2,n-1});
		    if (v.size() <= 2) {
			cout << v.size() << '\n';
			for (pair<int,int> p : v) {
			    cout << p.first+1 << ' ' << p.second+1 << '\n';
			}
			break;
		    }
		}
	}
	return 0;
}
