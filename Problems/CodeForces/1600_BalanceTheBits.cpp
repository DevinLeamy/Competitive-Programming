#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

pair<string, string> solve() {
	int n; cin >> n;
	string s; cin >> s;
	pair<string, string> res;
	PI cnts;
	int zeros = 0;
	if (s[0] == '0' || s.back() == '0')
		return {"", ""};
	cnts.first++;
	cnts.second++;
	res.first += "(";
	res.second += "(";
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '1') {
			if (cnts.first > 0 && cnts.second > 0) {
				if (s[i + 1] == '0' && (cnts.first - 1 == 0 && cnts.second - 1 == 0)) {
					res.first += "(";
					res.second += "(";
				} else {
					res.first += ")";
					res.second += ")";
				}
			} else {
				res.first += "(";
				res.second += "(";
			}
		} else {
			zeros++;
			if (cnts.first > cnts.second) {
				res.first += ")";
				res.second += "(";
			} else {
				res.second += ")";
				res.first += "(";		}
		}
		if (res.first.back() == ')')
			cnts.first--;
		else
			cnts.first++;
		if (res.second.back() == ')')
			cnts.second--;
		else
			cnts.second++;
//		view(res.first + " " + res.second);
		if (cnts.first < 0 || cnts.second < 0)
			return {"", ""};
	}
	cnts.first--;
	cnts.second--;
	res.first += ")";
	res.second += ")";
	if (cnts.first != 0 || cnts.second != 0)
		return {"", ""};
//	assert(zeros % 2 == 0);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		pair<string, string> res = solve();
		if (!res.first.empty()) {
			cout << "YES\n" << res.first << "\n" << res.second << "\n";
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
