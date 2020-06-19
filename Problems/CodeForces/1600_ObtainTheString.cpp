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
		string s, t; cin >> s >> t;
		vector<vector<int>> alp(s.length());
		vector<vector<int>> ind(26);
		for (int i = (int) s.length()-1; i >= 0; i--) {
			ind[s[i] - 'a'].pb(i);
			if (i == s.length() - 1) {
				for (int j = 0; j < 26; j++) {
					alp[i].pb(-1);
				}
			} else {
				for (int j = 0; j < 26; j++) {
					alp[i].pb(alp[i+1][j]);
				}
			}
			alp[i][s[i] - 'a'] = i;
		}
		int count = 1;
		int pos = 0;
		for (int i = 0; i < t.length(); i++) {
			int index = t[i] - 'a';
			if (ind[index].size() == 0) {
				count = -1;
				break;
			}
			if (pos == s.size() || alp[pos][index] == -1) {
				pos = ind[index][ind[index].size() - 1] + 1;
				count++;
			} else {
				pos = alp[pos][index] + 1;
			}
		}
		cout << count << endl;
	}
	return 0;
}
