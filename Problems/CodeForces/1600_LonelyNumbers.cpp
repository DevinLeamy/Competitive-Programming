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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	int mx = 1000000;
	vector<bool> prime(mx+1, true);
	prime[0] = false; prime[1] = false;
	for (int i = 2; i <= mx; i++) {
		if (prime[i]) {
			for (int j = i*2; j <= mx; j += i)
				prime[j] = false;
		}
	}
	
	vector<int> ans(mx+1);
	ans[0] = 0; ans[1] = 1;
	int count = 1;
	queue<ll> nxt;
	for (ll i = 2; i <= mx; i++) {
		if (prime[i]) {
			nxt.push(i*i);
			count++;
		} else if (nxt.front() == i) {
			count--;
			nxt.pop();
		}
		ans[i] = count;
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		printf("%d\n", ans[a]);
	}
	return 0;
}
