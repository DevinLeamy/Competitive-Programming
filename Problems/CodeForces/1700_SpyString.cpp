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

string A = "abcdefghijklmnopqrstuvwxyz";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, m; cin >> n >> m;
		string s; vector<string> str;
		for (int i = 0; i < n; i++) { cin >> s; str.pb(s); }
		vector<vector<int>> vals;
		for (int i = 0; i < m; i++) { vals.pb(vector<int>(26)); }
		for (string val : str) {
			for (int i = 0; i < m; i++) {
				vals[i][val[i] - 'a']++;
			}
		}
		string val = "";
		vector<int> change;
		for (int i = 0; i < m; i++) {
			bool f = false;
			for (int j = 0; j < 26; j++) {
				if (vals[i][j] == n) {
					val += A[j];
					f = true;
					break;
				}
			}
			if (!f) { val += "*"; change.pb(i); }
		}
		//Trival cases
		if (change.size() == 0) {
			cout << val << endl;
			continue;
		} else if (m == 1) {
			cout << "a" << endl;
			continue;
		} else if (change.size() == 1) {
			val[change[0]] = 'a';
			cout << val << endl;
			continue;
		}
		bool works = true;
		for (int i = 0; i < change.size(); i++) {
			for (int j = 0; j < 26; j++) {
				string temp = str[0];
				temp[change[i]] = A[j];
				works = true;
				for (string tt : str) {
					int count = 0;
					for (int k = 0; k < m; k++) {
						if (temp[k] != tt[k]) {
							count++;
						}
					}
					if (count > 1) { works = false; break; }
				}
				if (works) { val = temp; break; }
			}
			if (works) { break; }
		}
		if (works) { cout << val << endl; }
		else { cout << "-1" << endl; }
	}
	return 0;
}
