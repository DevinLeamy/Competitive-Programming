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
		ll n, k; cin >> n >> k;
		if (n % 2 == 1 && k % 2 == 0) { cout << "NO" << endl; continue; }
		if (n % 2 == 0 && k % 2 == 1 && n < k * 2) { cout << "NO" << endl; continue; }
		if (k > n) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		if (n % 2 == 0 && k % 2 == 1) {
			while (k != 1) {
				cout << 2 << " ";
				k--; n -= 2;
			}
			cout << n << "\n";
		} else {
			while (k != 1) {
				cout << 1 << " ";
				k--; n -= 1;
			}
			cout << n << "\n";
		}
	}
	return 0;
}
