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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int k; cin >> k;
	string s; cin >> s;
	int n = (int) s.size();
	vector<int> pos(n);
	vector<int> par(n);
	vector<vector<int>> child(n);
	int cur = pow(2, k - 1);
	for (int i = 0; i < n; i++) {
		if (i < pow(2, k - 1)) {
			if (s[i] == '?') {
				pos[i] = 2;
			} else {
				pos[i] = 1;
			}
		} else {
			int top = pos[child[i][0]]; // Lower index
			int btm = pos[child[i][1]]; // Higher index
			if (s[i] == '?') {
				pos[i] = top + btm;
			} else {
				pos[i] = (s[i] == '0')? top : btm;
			}
		}
		par[i] = i + cur;
		if (i + cur < n) {
			child[i + cur].pb(i);
		}
		if (i % 2 == 0) {
			cur--;
		}
	}
	int q; cin >> q;
	loop(q) {
		int p; char c; cin >> p >> c;
		p--;
		int i = p;
		s[i] = c;
		while (i < n) {
			if (i < pow(2, k - 1)) {
				if (s[i] == '?') {
					pos[i] = 2;
				} else {
					pos[i] = 1;
				}
			} else {
				int top = pos[child[i][0]]; // Lower index
				int btm = pos[child[i][1]]; // Higher index
				if (s[i] == '?') {
					pos[i] = top + btm;
				} else {
					pos[i] = (s[i] == '0')? top : btm;
				}
			}
			if (i == n - 1)
				break;
			i = par[i];
		}
		cout << pos[n - 1] << "\n";
	}
	return 0;
}
