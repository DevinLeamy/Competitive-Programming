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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	string no_sol = "NO SOLUTION\n";
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	if (n == 2 || n == 3) {
		cout << no_sol;
		return 0;
	}
	for (int i = 2; i <= n; i += 2) {
		cout << i << " ";
	}
	for (int i = 1; i <= n; i += 2) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}
