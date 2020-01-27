#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<string, set<string>> names; string name; int n; cin >> n;
	vector<string> lineOne; vector<string> lineTwo;
	loop(n) {
		cin >> name; lineOne.pb(name);
	}
	loop(n) {
		cin >> name; lineTwo.pb(name);
	}
	bool bad = false;
	loop(n) {
		string a = lineOne[i]; string b = lineTwo[i];
		if (a == b) {bad = true;}
		names[a].insert(b); names[b].insert(a);
		if (names[a].size() > 1) {bad = true;}
		if (names[b].size() > 1) {bad = true;}
	}
	if (bad) {
		cout << "bad" << endl;
	} else {
		cout << "good" << endl;
	}
	return 0;
}
