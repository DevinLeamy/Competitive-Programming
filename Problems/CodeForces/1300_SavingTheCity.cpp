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
		int a, b, put = 0; cin >> a >> b;
		string s; cin >> s;
		int n = (int) s.length();
		int last = (s[0] == '1')? a : 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') {
				put++;
			} else {
				if (last == 0) {
					last = a;
				} else {
					last = min(last+put*b, last + a);
				}
				put = 0;
			}
		}
		cout << last << endl;
	}
	return 0;
}
