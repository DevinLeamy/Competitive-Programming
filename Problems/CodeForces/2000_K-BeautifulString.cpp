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

string alph = "abcdefghijklmnopqrstuvwxyz";

bool valid_string(string s, int k) {
	vector<int> cnts(26, 0);
	for (int i = 0; i < s.length(); i++)
		cnts[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (cnts[i] > 0 && cnts[i] % k != 0)
			return false;
	return true;
}

string valid(int pos, string s, int k, int idx) {
	vector<int> cnts(26, 0);
	string res = "";
	s[pos] = alph[idx + 1];
	
	for (int i = 0; i <= pos; i++) {
		res += s[i];
		cnts[s[i] - 'a'] = (cnts[s[i] - 'a'] + 1) % k;
	}
	
	int min_add = 0;
	for (int i = 0; i < 26; i++)
		min_add += (cnts[i] == 0)? 0 : k - cnts[i];
	
	res += string((int) s.length() - (pos + 1) - min_add, 'a');
	for (int i = 0; i < 26; i++) {
		int add_cnt = (cnts[i] == 0)? 0 : k - cnts[i];
		res += string(add_cnt, alph[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		if (n % k != 0) {
			cout << -1 << endl;
			continue;
		}
		if (valid_string(s, k)) {
			cout << s << endl;
			continue;
		}
		PI pos_change = {-1,-1};
		vector<int> cnt(26);
		int min_add = 0;
		for (int i = 0; i < n; i++) {
			int rem = n - i - min_add;
			int idx = s[i] - 'a';
			if (min_add < 0 || rem < 0) {
				min_add -= (cnt[idx] == 0? 0 : k - cnt[idx]);
				cnt[idx] = (cnt[idx] + 1) % k;
				min_add += (cnt[idx] == 0? 0 : k - cnt[idx]);
				continue;
			};
			if (rem % k == 0 && rem != 0 && idx != 25) pos_change = {i, s[i] - 'a'};
			else if (idx != 25){
				int temp = min_add;
				for (int j = idx + 1; j < 26; j++) {
					if (cnt[j] == 0) continue;
					temp -= (cnt[j] == 0? 0 : k - cnt[j]);
					temp += (cnt[j] == 0? 0 : k - cnt[j]);
					int new_rem = n - i - temp;
					if (new_rem % k == 0) {
						pos_change = {i, j - 1};
						break;
					}
					temp = min_add;
				}
			}
			min_add -= (cnt[idx] == 0? 0 : k - cnt[idx]);
			cnt[idx] = (cnt[idx] + 1) % k;
			min_add += (cnt[idx] == 0? 0 : k - cnt[idx]);
		}
		if (pos_change.first == -1) cout << "-1" << endl;
		else {
			string res = valid(pos_change.first, s, k, pos_change.second);
			cout << res << endl;
		}
	}
	return 0;
}
