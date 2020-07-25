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

string alphabet = "abcdefghijklmnopqrstuvwxyz";
int getMin(char cur, string s) {
	if (s.length() == 1) {
		if (s[0] == cur) {
			return 0;
		} else {
			return 1;
		}
	}
	int sumF = 0;
	int sumB = 0;
	for (int i = 0; i < (int) s.length() / 2; i++) {
		if (s[i] != cur) {
			sumF++;
		}
	}
	for (int i = (int) s.length() / 2; i < s.length(); i++) {
		if (s[i] != cur) {
			sumB++;
		}
	}
	int index = cur - 'a';
	char next = alphabet[index + 1];
	return min(
		getMin(next, s.substr(0, s.length() / 2)) + sumB,
		getMin(next, s.substr(s.length() / 2, s.length())) + sumF
	);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		cout << getMin('a', s) << endl;
	}
	return 0;
}
