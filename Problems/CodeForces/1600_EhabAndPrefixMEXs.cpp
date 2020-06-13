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
	int n, a; cin >> n;
	vector<int> vals;
	vector<bool> taken(n+1);
	queue<int> put;
	queue<int> missed;
	for (int i = 0; i < n; i++) { cin >> a; taken[a] = true; vals.pb(a); }
	for (int i = 0; i <= 1000000; i++) {
		if (i <= n && !taken[i]) {
			put.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		int val = vals[i];
		if (missed.empty()) {
			cout << put.front() << " ";
			put.pop();
			missed.push(val);
		} else {
			if (missed.front() == val) {
				cout << put.front() << " ";
				put.pop();
			} else {
				cout << missed.front() << " ";
				missed.pop();
				if (missed.empty() || missed.back() != val) {
					missed.push(val);
				}
			}
		}
		
	}
	return 0;
}
