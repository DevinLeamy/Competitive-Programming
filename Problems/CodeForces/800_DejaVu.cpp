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
#define view(h) cout<< "DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		string s; cin >> s;
		bool can = false;
		int pos = -1;
		for (int i = 0; i < (int) s.length(); i++) {
			if (s[i] != 'a') {
				pos = i;
				can = true;
			}
		}
		if (!can) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			string test = s + "a";
			string temp = test;
			reverse(temp.begin(), temp.end());
			if (temp == test)
				cout << "a" + s << endl;
			else
				cout << test << endl;
		}
	}
	return 0;
}
