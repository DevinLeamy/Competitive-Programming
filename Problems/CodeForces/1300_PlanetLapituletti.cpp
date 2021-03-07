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
		int h, m; cin >> h >> m;
		string s2; cin >> s2;
		int cur_h = stoi(s2.substr(0, 2));
		int cur_m = stoi(s2.substr(3, 2));
		vector<char> invalid = { '4', '7', '6', '9', '3'};
		while (true) {
			string cur_s_m = to_string(cur_m);
			if (cur_s_m.length() == 1) cur_s_m = "0" + cur_s_m;
			string temp_m = cur_s_m;
			string cur_h_m = to_string(cur_h);
			if (cur_h_m.length() == 1) cur_h_m = "0" + cur_h_m;
			string temp_h = cur_h_m;
			bool valid = true;
			for (int i = 0; i < 2; i++) {
				for (char c : invalid) {
					if (cur_s_m[i] == c || cur_h_m[i] == c) {
						valid = false;
						break;
					}
				}
				if (cur_s_m[i] == '5') {
					cur_s_m[i] = '2';
				} else if (cur_s_m[i] == '2') {
					cur_s_m[i] = '5';
				}
				if (cur_h_m[i] == '5') {
					cur_h_m[i] = '2';
				} else if (cur_h_m[i] == '2') {
					cur_h_m[i] = '5';
				}
			}
			int ref_m = (cur_h_m[1] - '0') * 10 + (cur_h_m[0] - '0');
			int ref_h = (cur_s_m[1] - '0') * 10 + (cur_s_m[0] - '0');
			if (ref_m < m && ref_h < h && valid) {
				cout << temp_h << ":" << temp_m << endl;
				break;
			}
			cur_m++;
			if (cur_m == m) {
				cur_h = (cur_h + 1) % h;
				cur_m = 0;
			}
		}
	}
	return 0;
}
