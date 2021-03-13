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

bool solve() {
	int n; cin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	int longest = 0;
	int cnt_l = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		if (vals[i] < vals[i + 1]) {
			while (i != n - 1 && vals[i] < vals[i+1]) {
				cnt++;
				i++;
			}
		} else {
			while (i != n - 1 && vals[i] > vals[i+1]) {
				cnt++;
				i++;
			}
		}
		if (cnt > 0)
			i--;
		if (cnt > longest) {
			cnt_l = 1;
			longest = cnt;
		} else if (cnt == longest)
			cnt_l++;
	}
	
	if (cnt_l != 2 || longest % 2 == 1)
		return false;
	for (int i = 1; i < n - 1; i++) {
		if (vals[i] > vals[i - 1] && vals[i] > vals[i + 1]) {
			int lf = i;
			int lf_cnt = 0;
			while (lf != 0 && vals[lf] > vals[lf - 1]) {
				lf_cnt++;
				lf--;
			}
			int r = i;
			int r_cnt = 0;
			while (r != n-1 && vals[r] > vals[r + 1]) {
				r_cnt++;
				r++;
			}
			if (lf_cnt == longest && r_cnt == longest)
				return true;
			i = r;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	if (solve())
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}
