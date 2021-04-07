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
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int q, x; cin >> q >> x;
	ll cur_mex = 0;
	vector<int> cnts(1000005);
	vector<ll> minmult(x);
	for (int i = 0; i < x; i++)
		minmult[i] = i;
	loop(q) {
		ll a; cin >> a;
		ll val = a % x;
		if (minmult[val] < 500005)
			cnts[minmult[val]]++;
		minmult[val] += x;
		while (cnts[cur_mex] > 0)
			cur_mex++;
		cout << cur_mex << endl;
	}
	return 0;
}
