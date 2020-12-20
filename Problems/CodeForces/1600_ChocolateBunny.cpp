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

int ask(int a, int b) {
	int res; a++; b++;
	cout << "? " << a << " " << b << endl;
	cout.flush();
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<int> ans(n);
	int max = 0;
	for (int i = 1; i < n; i++) {
		int a = ask(max, i);
		int b = ask(i, max);
		if (a > b) {
			// ans[max] < ans[i]
			ans[max] = a;
			max = i;
		} else {
			// ans[max] > ans[i]
			ans[i] = b;
		}
	}
	ans[max] = n;
	cout << "! ";
	for (int val : ans) cout << val << " ";
	return 0;
}
