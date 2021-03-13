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
	int n, m; cin >> n >> m;
	string s1, s2; cin >> s1 >> s2;
	
	int cur = 0;
	vector<int> left_most(m);
	
	for (int i = 0; i < s1.length() && cur != m; i++) {
		while (s1[i] != s2[cur])
			i++;
		left_most[cur] = i;
		cur++;
	}
	
	int ans = 0;
	cur = m - 1;
	for (int i = n - 1; i >= 0 && cur != 0; i--) {
		while (s1[i] != s2[cur])
			i--;
		
		ans = max(i - left_most[cur - 1], ans);
		cur--;
	}
	
	cout << ans << endl;
	return 0;
}
