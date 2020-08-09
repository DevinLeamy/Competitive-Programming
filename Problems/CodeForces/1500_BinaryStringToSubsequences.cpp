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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		queue<int> ones;
		queue<int> zeros;
		vector<int> vals(n);
		int groups = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (!zeros.empty()) {
					vals[i] = zeros.front();
					ones.push(vals[i]);
					zeros.pop();
				} else {
					vals[i] = groups+1;
					ones.push(vals[i]);
					groups++;
				}
			} else {
				if (!ones.empty()) {
					vals[i] = ones.front();
					zeros.push(vals[i]);
					ones.pop();
				} else {
					vals[i] = groups + 1;
					zeros.push(vals[i]);
					groups++;
				}
			}
		}
		cout << groups << endl;
		for (int i = 0; i < n; i++) {
			cout << vals[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
