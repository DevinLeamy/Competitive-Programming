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
	string s; cin >> s;
	int ans = 1;
	int cur = 1;
	char last = s[0];
	for (int i = 1; i < (int) s.size(); i++) {
		if (s[i] == last)
			cur++;
		else {
			cur = 1;
			last = s[i];
		}
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}
