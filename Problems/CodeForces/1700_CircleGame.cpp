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

double dist(ll a, ll b) {
	if (b == 0) return a;
	return sqrt(a*a + b*b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int d, k; cin >> d >> k;
		bool found = false;
		for (int i = 0; i <= d; i++) {
			ll x = k * i;
			ll y = k * i;
			if (dist(x, y) <= d && dist(x + k, y) > d) {
				found = true;
				break;
			}
			if (dist(x+k, y) <= d && dist(x+2*k, y) > d && dist(x+k, y+k) > d) break;
		}
		if (dist(2*k, 0) <= d && dist(2*k, k) > d && dist(3*k, 0) > d) {
			found = true;
		}
		if (found) printf("Utkarsh\n");
		else printf("Ashish\n");
	}
	return 0;
}
