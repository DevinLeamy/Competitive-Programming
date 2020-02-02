#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll h, d; cin >> h;
	loop(h) {
		cin >> d;
		if (d < 3) {cout << 0 << endl;}
		int rem = d % 3;
		if (rem == 0) {
			cout << ((d/3) * (d/3) * (d/3)) << endl;
		} else if (rem == 1) {
			cout << (((d/3)+1) * (d/3) * (d/3)) << endl;
		} else {
			cout << (((d/3)+1) * ((d/3)+1) * (d/3)) << endl;
		}
	}
	return 0;
}
