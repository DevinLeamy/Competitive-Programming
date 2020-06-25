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
	int t; cin >> t;
	loop(t) {
		int min = INF;
		string s; cin >> s;
		int lp = 0;
		vector<int> count(4);
		for (int i = 0; i < s.length(); i++) {
			char val = s[i];
			if (count[val - '0'] > 0) {
				if (s[lp] == val) {
					count[1] = 0; count[2] = 0; count[3] = 0;
					lp++;
					count[s[lp] - '0']++;
					i = lp;
				} else {
					count[val - '0']++;
				}
			} else {
				count[val - '0']++;
			}
			if (count[1] > 0 && count[2] > 0 && count[3] > 0) {
				min = std::min(count[1] + count[2] + count[3], min);
			}
		}
		cout << (min==INF? 0:min) << endl;
	}
	return 0;
}
