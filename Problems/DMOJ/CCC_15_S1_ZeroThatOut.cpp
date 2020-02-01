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
	int n, v, total = 0; cin >> n;
	vector<int> values;
	loop(n) {
		cin >> v; if (v == 0) {total -= values.back(); values.pop_back();}
		else { total += v; values.pb(v); }
	}
	cout << total << endl;
	return 0;
}
