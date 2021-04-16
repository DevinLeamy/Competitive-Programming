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

vector<int> vals(1234567);
vector<int> queries(1234567);
int n, q;
int f(int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += (vals[i] <= x)? 1 : 0;
	}
	for (int i = 0; i < q; i++) {
		if (queries[i] > 0 && queries[i] <= x)
			count++;
		else if (queries[i] < 0 && abs(queries[i]) <= count)
			count--;
	}
	return count;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	cin >> n >> q;
	
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	for (int i = 0; i < q; i++)
		cin >> queries[i];

	if (f(1000001) == 0) {
		cout << 0 << endl;
		return 0;
	}
	int lp = 0;
	int rp = 1000001;
	while (rp - lp > 1) {
		int mid = (rp + lp) / 2;
		if (f(mid) > 0) {
			rp = mid;
		} else {
			lp = mid;
		}
	}
	cout << rp << endl;
	return 0;
}
