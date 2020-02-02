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
	int n, v; vector<int> values; cin >> n;
	loop(n) {cin >> v; values.pb(v);}
	sort(values.begin(), values.end());
	string output = ""; bool low = true;
	vector<int> lowV; vector<int> highV;
	loop(n) {
		if (i < (n/2 + n%2)) {
			lowV.pb(values[i]);
		} else {
			highV.pb(values[i]);
		}
	}
	int current = 0;
	while (n > 0) {
		if (low) {
			output += to_string(lowV[lowV.size() - 1 - current]);
			output += " ";
		} else {
			output += to_string(highV[current]);
			output += " ";
		}
		if (!low) {current++;}
		low = !low;\
		n--;
	}
	cout << output << endl;
	return 0;
}
