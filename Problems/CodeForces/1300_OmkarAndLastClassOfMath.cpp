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

bool isPrime(ll val) {
	if (val == 2) return true;
	for (int i = 2; i * i <= val; i++) {
		if (val % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll n; cin >> n;
		if (isPrime(n)) {
			cout << n-1 << " " << 1 << endl;
			continue;
		}
		ll temp = n;
		int cur = 1;
		ll min = n-1;
		ll curB = -1;
		while (temp % 2 == 0) {
			cur *= 2;
			temp /= 2;
			ll val = max((n / cur) * (cur - 1), n/cur);
			if (val < min) {
				min = val;
				curB = cur;
			}
		}
		for (int i = 2; i * i <= n; i++) {
			while (temp % i == 0) {
				cur *= i;
				ll val = max((n / cur) * (cur - 1), n/cur);
				if (val < min) {
					min = val;
					curB = cur;
				}
				temp /= i;
			}
		}
		cout << (n / curB) * (curB - 1) << " " << n/curB << endl;
	}
	return 0;
}
