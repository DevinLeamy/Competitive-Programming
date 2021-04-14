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

bool is_prime(ll n) {
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	
	return true;
}

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int a, b, c; cin >> a >> b >> c;
		ll start = pow(10, c - 1) + 1;
		while (!is_prime(start))
			start++;
		ll ans_a = 1;
		while (to_string(ans_a * start).length() != a)
			ans_a *= 10;
		
		ll ans_b = 1;
		
		while (to_string(ans_b * start).length() != b)
			ans_b *= 10;
		while (!is_prime(ans_a) || to_string(ans_a * start).length() != a) {
			ans_a++;
		}
		
		while (!is_prime(ans_b) || to_string(ans_b * start).length() != b || ans_b == ans_a) {
			ans_b++;
		}
		cout << ans_a*start << " " << ans_b * start << endl;
	}
	return 0;
}
