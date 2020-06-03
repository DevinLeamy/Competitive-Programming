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
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

ll getVal(ll row, ll col) {
	double dist = row + col;
	ll base = (dist / 2.0) * (1 + dist) + 1;
	return base + row;
}
ll sumFrom(double first, double last) {
	return (((last - first) + 1) / 2.0) * (last + first);
}
ll sumInc(double last) {
	return ((1.0/6.0) * last) * (last + 1) * (last + 2);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		ll dC = (c2 - c1);
		ll dR = (r2 - r1);
		ll x = getVal(r1, c1);
		//Top & Left
		ll y = getVal(r1, c1 + 1) - x;
		ll top = ((dC + 1) * x) + (sumFrom(0, dC) * y) + sumInc(dC - 1);
		ll left = ((dR + 1) * x) + (sumFrom(0, dR) * y) + sumInc(dR - 1) + sumFrom(0, dR);
		//Bottom
		x = getVal(r2, c1);
		y = getVal(r2, c1+1) - x;
		ll bottom = ((dC + 1) * x) + (sumFrom(0, dC) * y) + sumInc(dC - 1);
		//Right
		x = getVal(r1, c2);
		y = getVal(r1, c2+1) - x;
		ll right = ((dR + 1) * x) + (sumFrom(0, dR) * y) + sumInc(dR - 1) + sumFrom(0, dR);
		//Min and Max path lengths
		ll min = top + right - getVal(r1, c2);
		ll max = left + bottom - getVal(r2, c1);
		
		ll total = (max - min) + 1;
		cout << total << endl;
	}
	return 0;
}
//If you're at a cell (r, c) and go to (r+1, c) [down] your total increases by (r+c) + 1
//If you're at a cell (r, c) and go to (r, c+1) [right] your total increases by (r+c)
