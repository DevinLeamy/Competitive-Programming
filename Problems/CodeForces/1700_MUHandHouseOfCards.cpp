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
	ll n; cin >> n;
	ll cur_h = 0;
	ll cnt = 0;
	while (1) {
		ll cards_top = (3ll * cur_h * cur_h + 7ll * cur_h + 4ll)/2;
		ll rem = n - cards_top;
		if (rem < 0)
			break;
		if (rem == 0 || rem % 3 == 0) {
			cnt++;
		}
		cur_h++;
	}
	cout << cnt << endl;
	return 0;
}
