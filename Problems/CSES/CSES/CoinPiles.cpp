#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		ll a, b; cin >> a >> b;
		if (a < b)
			swap(a, b);
		if (b * 2 < a) {
			cout << "NO" << endl;
			continue;
		} else if ((a + b) % 3 != 0) {
			cout << "NO" << endl;
			continue;
		} else
			cout << "YES" << endl;
		
	}
	return 0;
}
