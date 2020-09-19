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
	vector<int> vals(n);
	vector<bool> used(n);
	for (int i = 0; i < n; i++) cin >> vals[i];
	sort(vals.begin(), vals.end());
	int count = 0;
	for (int i = 0; i < n; i++) {
		int stack = 1;
		if (!used[i]) {
			count++;
			for (int j = i+1; j < n; j++) {
				if (!used[j] && vals[j] >= stack) {
					stack++;
					used[j] = true;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
