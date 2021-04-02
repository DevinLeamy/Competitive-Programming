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
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		ll total = i * i;
		ll moves = (total - 1) * total / 2; // Total ways to place two nights
		if (i > 2) {
			moves -= (i - 2) * (i - 1) * 4; // Number of positions in which they attack each other
		}
		cout << moves << endl;
	}
	
	return 0;
}
