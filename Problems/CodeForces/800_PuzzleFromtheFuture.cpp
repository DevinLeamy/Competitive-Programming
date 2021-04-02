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
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		string ans = "";
		int last = -1;
		for (int i = 0; i < n; i++) {
			int cur = s[i] - '0';
			if (last == cur + 1) {
				ans += "0";
				last = cur;
			} else {
				ans += "1";
				last = cur + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
