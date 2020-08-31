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

const string val = "abacaba";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		bool good = false;
		string ans;
		for (int i = 0; i <= n-7; i++) {
			bool works = true;
			string temp = s;
			for (int j = i; j < i + 7; j++) {
				if (s[j] == val[j - i] || s[j] == '?') {
					temp[j] = val[j - i];
				} else {
					works = false;
				}
			}
			if (!works) continue;
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (temp[j] == '?') {
					temp[j] = 'd';
				}
			}
			for (int j = 0; j <= n-7; j++) {
				if (temp.substr(j, 7) == val) {
					count++;
				}
			}
			if (count == 1) {
				ans = temp;
				good = true;
				break;
			}
		}
		if (good) {
			cout << "YES" << endl;
			cout << ans << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
