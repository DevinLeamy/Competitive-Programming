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
		string s; cin >> s;
		bool found = false;
		for (int mask = 1; mask <= (1 << 3); mask++) {
			int cnt_open = 0;
			bool valid = true;
			for (int i = 0; i < (int) s.length(); i++) {
				if (1 & (mask >> (s[i] - 'A')))
					cnt_open++;
				else
					cnt_open--;
				valid &= cnt_open >= 0;
			}
			valid &= cnt_open == 0;
			if (valid)
				found = true;
		}
		if (found)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
