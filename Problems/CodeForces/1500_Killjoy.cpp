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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, x; cin >> n >> x;
		vector<int> vals(n);
		int left = n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (vals[i] == x)
				left--;
			else
				sum += vals[i];
		}
		if (left == 0) cout << 0 << endl;
		else if ((sum / n == x && sum % n == 0) || (left != n)) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}
