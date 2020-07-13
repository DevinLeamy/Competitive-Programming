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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, t, a, b; cin >> n >> k;
	vector<int> valsA;
	vector<int> valsB;
	vector<int> joint;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> b;
		if (a && b) {
			joint.pb(t);
		} else {
			if (a) { valsA.pb(t); }
			if (b) { valsB.pb(t); }
		}
	}
	sort(valsB.begin(), valsB.end());
	sort(valsA.begin(), valsA.end());
	for (int i = 0; i < min(valsA.size(), valsB.size()); i++) {
		joint.pb(valsA[i] + valsB[i]);
	}
	sort(joint.begin(), joint.end());
	if (joint.size() >= k) {
		int total = 0;
		for (int i = 0; i < k; i++) {
			total += joint[i];
		}
		cout << total << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
