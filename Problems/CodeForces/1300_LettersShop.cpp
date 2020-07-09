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

vector<vector<int>> vals;
vector<int> name(26);

bool works(int index) {
	for (int i = 0; i < 26; i++) {
		if (name[i] > vals[index][i]) {
			return false;
		}
	}
	return true;
}

int binarySearch(int left, int right) {
	if (left >= right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (works(mid)) {
		return binarySearch(left, mid);
	} else {
		return binarySearch(mid+1, right);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s, m; cin >> s;
	vals.pb(vector<int>(26));
	for (int i = 0; i < n; i++) {
		int index = s[i] - 'a';
		vals.pb(vector<int>(26));
		vals[i + 1][index]++;
		for (int j = 0; j < 26; j++) {
			vals[i+1][j] += vals[i][j];
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> m;
		for (int j = 0; j < 26; j++) {
			name[j] = 0;
		}
		for (int j = 0; j < m.length(); j++) {
			int index = m[j] - 'a';
			name[index]++;
		}
		int res = binarySearch(1, n);
		while(!works(res)) {
			res++;
		}
		cout << res << "\n";
	}
	return 0;
}
