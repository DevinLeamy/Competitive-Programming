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
	int n; cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	if (n == 1) {
		cout << "1 1" << endl;
		cout << -vals[0] << endl;
		cout << "1 1" << endl;
		cout << "0" << endl;
		cout << "1 1" << endl;
		cout << "0" << endl;
		return 0;
	}
	cout << "1 " << n << endl;
	for (int i = 0; i < n; i++) {
		ll diff = (n-1) - (vals[i] % (n-1));
		
		cout << diff * n << " ";
		vals[i] += diff * n;
	}
	cout << endl;
	cout << "1 " << n-1 << endl;
	for (int i = 0; i < n-1; i++) {
		cout << -1 * vals[i] << " ";
		vals[i] = 0;
	}
	cout << endl;
	cout << "2 " << n << endl;
	for (int i = 1; i < n; i++) {
		cout << -1 * vals[i] << " ";
	}
	cout << endl;
	return 0;
}
