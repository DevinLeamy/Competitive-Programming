#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<short> overtakes;
	vector<PI> speeds;
	for (int i = 0; i < n; i++) {
		int t, speed; cin >> t;
		if (t == 1) { // changes speed
			cin >> speed;
			speeds.pb({1, speed});
		} else if (t == 2) { // overtakes
			overtakes.pb(2);
		} else if (t == 3) { // set limit
			cin >> speed;
			speeds.pb({3, speed});
		} else if (t == 4) { // allow overtakes
			overtakes.pb(4);
		} else if (t == 5) { // remove limit
			speeds.pb({3, 420});
		} else {
			overtakes.pb(6); // disallow overtakes
		}
	}
	
	int ans_o = 0;
	int cannot_o = 0;
	for (int val : overtakes) {
		if (val == 2) {
			ans_o += cannot_o;
			cannot_o = 0;
		} else if (val == 4) {
			cannot_o = 0;
		} else {
			cannot_o++;
		}
	}
	
	int ans_s = 0;
	int m = (int) speeds.size();
	int speed = 0;
	
	stack<int> vals;
	for (int i = 0; i < m; i++) {
		PI val = speeds[i];
		if (val.first == 1) {
			speed = val.second;
		} else if (val.first == 3) {
			vals.push(val.second);
		}
		while (!vals.empty() && vals.top() < speed) {
			ans_s++;
			vals.pop();
		}
	}
	printf("%d\n", ans_s + ans_o);
	return 0;
}
