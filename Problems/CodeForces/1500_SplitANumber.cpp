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

string addStrings(string a, string b) {
	string ans = "";
	if (a.length() < b.length()) {
		string temp = a;
		a = b;
		b = temp;
	}
	int rem = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < a.length(); i++) {
		int valA = a[i] - '0';
		int valB = 0;
		if (i < b.length()) {
			valB = b[i] - '0';
		}
		int sum = valA + valB + rem;
		if (sum >= 10) {
			rem = 1;
		} else {
			rem = 0;
		}
		ans = to_string(sum % 10) + ans;
	}
	if (rem > 0) {
		ans = '1' + ans;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int min = INF;
	pair<int, int> mins = {-1, -1};
	for (int i = 1; i < n; i++) {
		if (s[i] != '0') {
			int val = std::max(i, n - i);
			if (val == min) {
				if (mins.first == -1) {
					mins.first = i;
				} else {
					mins.second = i;
				}
			} else if (val < min) {
				min = val;
				mins = {i, -1};
			}
		}
	}
	if (mins.first != -1 && mins.second != -1) {
		string a = addStrings(s.substr(0, mins.first), s.substr(mins.first));
		string b = addStrings(s.substr(0, mins.second), s.substr(mins.second));
		if (a <= b) {
			cout << a;
		} else {
			cout << b;
		}
	} else {
		cout << addStrings(s.substr(0, mins.first), s.substr(mins.first));
	}
	
	return 0;
}
