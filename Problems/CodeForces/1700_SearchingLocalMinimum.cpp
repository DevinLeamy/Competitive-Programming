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
#define INF 21474836
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
#define view(h) cout<<"DEBUG: " << h << endl
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int MAXN = 100005;
vector<int> prem(MAXN);
int query(int idx) {
	if (prem[idx] != 0)
		return prem[idx];
	cout << "? " << idx << endl;
	cout.flush();
	cin >> prem[idx];
	return prem[idx];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	prem[0] = INF;
	prem[n + 1] = INF;
	int l = 1, r = n + 1;
	while (1) {
		if (query(l) < min(query(l - 1), query(l + 1))) {
			cout << "! " << l << endl;
			break;
		}
		int mid = (l + r) / 2;
		if (query(mid) < query(l)) {
			int temp = l;
			l = mid;
			if (query(l - 1) < query(l)) { // Edge case: new a_l > a_{l - 1}
				r = mid;
				l = temp + 1;
			}
		} else {
			r = mid;
		}
	}
	return 0;
}
