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
	int n; cin >> n;
	vector<ll> vals(n);
	vector<string> str(n);
	bool works = true;
	for (int i = 0; i < n; i++) cin >> vals[i];
	for (int i = 0; i < n; i++) cin >> str[i];
	PL lastV = {0, vals[0]};
	for (int i = 1; i < n; i++) {
		string last = str[i-1];
		string rLast = str[i-1];
		string cur = str[i];
		string rCur = str[i];
		reverse(rLast.begin(), rLast.end());
		reverse(rCur.begin(), rCur.end());
		PL newV = {LINF, LINF};
		if (last <= cur && lastV.first != LINF) {
			newV.first = min(newV.first, lastV.first);
		}
		if (last <= rCur && lastV.first != LINF) {
			newV.second = min(newV.second, vals[i] + lastV.first);
		}
		if (rLast <= cur && lastV.second != LINF) {
			newV.first = min(newV.first, lastV.second);
		}
		if (rLast <= rCur && lastV.second != LINF) {
			newV.second = min(newV.second, vals[i] + lastV.second);
		}
		if (newV.first == LINF && newV.second == LINF) {
			works = false;
			break;
		}
		lastV = newV;
	}
	if (!works) {
		cout << -1 << endl;
	} else {
		cout << min(lastV.first, lastV.second) << endl;
	}
	return 0;
}
