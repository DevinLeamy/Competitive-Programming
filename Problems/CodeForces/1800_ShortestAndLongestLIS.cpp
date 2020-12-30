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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		
		vector<int> min(n), max(n);
		int cur = n, last = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '>' || i == n - 1) {
				for (int j = i; j >= last; j--) {
					min[j] = cur; cur--;
				}
				last = i + 1;
			}
		}
		for (int val : min) printf("%d ", val);
		printf("\n");
		
		cur = 1; last = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '<' || i == n - 1) {
				for (int j = i; j >= last; j--) {
					min[j] = cur; cur++;
				}
				last = i + 1;
			}
		}
		for (int val : min) printf("%d ", val);
		printf("\n");
		
		
	}
	return 0;
}
