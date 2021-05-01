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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int n;
int MAXN = 300005;
vector<int> vals(MAXN);
vector<int> cnts(MAXN);
vector<bool> ans(MAXN);

vector<bool> solve() {
	cin >> n;
	int m = INF;
	for (int i = 0; i <= n; i++) {
		cnts[i] = 0;
		ans[i] = false;
	}
	ans[0] = true;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		m = min(m, vals[i]);
		if (cnts[vals[i]])
			ans[0] = false;
		cnts[vals[i]]++;
	}
	if (m == 1)
		ans[n - 1] = true;

	int l = 0, r = n - 1;
	for(int i = n - 1; i > 0; --i) {
        if(!ans[n-1]) break;
        ans[i] = true;
        int nxt = n-i;
        if(--cnts[nxt] == 0 && (vals[l]==nxt || vals[r]==nxt) && cnts[nxt+1]) {
            if (vals[l]==nxt)l++;
            else if (vals[r]==nxt)r--;
            continue;
        }
        break;
    }
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		vector<bool> ans = solve();
		for (int i = 0; i < n; i++) {
			if (!ans[i])
				cout << 0;
			else
				cout << 1;
		}
		cout << endl;
	}
	return 0;
}
