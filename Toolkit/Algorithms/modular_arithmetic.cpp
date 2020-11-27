//Algorithms for computing answers modulo M
#define ll long long

using namespace std;

ll mod = 1000000007ll;
ll mult(ll a, ll b) {
	return (a * b) % mod;
}

ll add(ll a, ll b) {
	return (a + b) % mod;
}

ll sub(ll a, ll b) {
	return (a + mod - b) % mod;
}

ll binexp(ll a, ll b) {
	ll res = 1;
	if (a <= 0) return 1;
	while(b > 0) {
		if (b % 2 == 1) res *= a;
		a *= a;
		a %= mod;
		res %= mod;
		b /= 2;
	}
	return res;
}
//Only works if mod is prime
ll divide(ll a, ll b) {
	return (a * binexp(b, mod-2)) % mod;
}

ll fact(ll n) {
	if (n <= 0) return 1;
	ll res = 1;
	while (n > 0) {
		res *= n;
		n--;
		res %= mod;
	}
	return res;
}

ll nCr(int n, int r) {
	if (r > n) return 0;
	return divide(fact(n), mult(fact(r), fact(n - r)));
}

int main() {
	return 0;
}
