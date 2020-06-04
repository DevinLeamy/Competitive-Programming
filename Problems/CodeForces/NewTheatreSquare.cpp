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
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, m, x, y, w = 0;
		string line;
		cin >> n >> m >> x >> y;
		vector<vector<bool>> isBlack;
		for (int i = 0; i < n; i++) {
			isBlack.pb(vector<bool>());
			cin >> line;
			for (int j = 0; j < m; j++) {
				isBlack[i].pb(line[j] == '*');
				if (line[j] == '.') {
					w++;
				}
				
			}
		}
		if (2*x <= y) {
			cout << x * w << endl;
			continue;
		}
		int cost = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m-1; j++) {
				if (!isBlack[i][j] && !isBlack[i][j+1]) {
					cost += y;
					isBlack[i][j] = true;
					isBlack[i][j+1] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!isBlack[i][j]) {
					cost += x;
				}
			}
		}
		cout << cost << endl;
	}
	return 0;
}
