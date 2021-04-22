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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, k; cin >> n >> k;
		vector<int> vals(n);
		for (int i = 0; i < n; i++)
			cin >> vals[i];
		for (int i = 0; i < n; i++) {
			while (k > 0 && vals[i] != 0) {
				vals[i]--;
				k--;
				vals[n - 1]++;
			}
		}
		for (int val : vals)
			cout << val << " ";
		cout << endl;
	}
	return 0;
}
