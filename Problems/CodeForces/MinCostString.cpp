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

string alp = "abcdefghijklmnopqrstuvwxyz";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, k; cin >> n >> k;
	vector<int> next(k);
	for (int i = 0; i < k; i++)
		next[i] = i;
	next[0] = 1 % k;
	string ans = "a";
	int last = 0;
	for (int i = 1; i < n; i++) {
		ans += alp[next[last]];
		int temp = next[last];
		next[last] = (next[last] + 1) % k;
		last = temp;
	}
	cout << ans << endl;
	return 0;
}
