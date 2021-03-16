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
		int q, d; cin >> q >> d;
		int top = 10 * d - 1;
		vector<bool> valid(top + 1);
		valid[0] = true;
		for (int i = 1; i <= top; i++) {
			for (int j = d; j <= i; j++) {
				string val = to_string(j);
				bool contains = false;
				for (int k = 0; k < val.length(); k++)
					contains |= val[k] - '0' == d;
				if (!contains)
					continue;
				if (valid[i - j])
					valid[i] = true;
			}
		}
		for (int i = 0; i < q; i++) {
			ll a; cin >> a;
			if (a > top || valid[a])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		
	}
	return 0;
}
