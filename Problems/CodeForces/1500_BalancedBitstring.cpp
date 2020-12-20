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
		int n, k; cin >> n >> k;
		string s; cin >> s;
		bool pos = true;
		for (int i = k; i < n; i++) {
			if (s[i] == s[i-k]) continue;
			if (s[i-k] == '?') s[i-k] = s[i];
			else if (s[i] == '?') s[i] = s[i-k];
			else pos = false;
		}
		int ones = 0, zeros = 0, len = 0;
		for (int i = 0; i < n; i++) {
			if (len == k) {
				if (s[i-k] == '1') ones--;
				else if (s[i-k] == '0') zeros--;
				len--;
			}
			if (s[i] == '1') ones++;
			else if (s[i] == '0') zeros++;
			len++;
			if (ones > k/2 || zeros > k/2) pos = false;
		}
		cout << (pos? "YES":"NO") << endl;
	}
	return 0;
}
