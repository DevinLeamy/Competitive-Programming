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
		ll row, col; cin >> row >> col;
		if (row >= col) {
			ll cur = (row - 1) * (row - 1) + row;
			if (row > col) {
				if (row & 1)
					cur -= (row - col);
				else
					cur += (row - col);
			}
			cout << cur << endl;
		} else {
			ll cur = (col - 1) * (col - 1) + col;
			if (col > row) {
				if (col & 1)
					cur += (col - row);
				else
					cur -= (col - row);
			}
			cout << cur << endl;
		}
		
	}
	return 0;
}
