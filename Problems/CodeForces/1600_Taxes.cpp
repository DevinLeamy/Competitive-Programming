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


bool isPrime(ll n) {
	if (n == 2) return true;
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	ll n; cin >> n;
	if (isPrime(n)) cout << 1 << endl;
	else if (n % 2 == 0 || isPrime(n-2)) cout << 2 << endl;
	else cout << 3 << endl;
	return 0;
}
