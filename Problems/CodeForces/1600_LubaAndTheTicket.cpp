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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	string s; cin >> s;
	
	vector<int> first(10);
	vector<int> last(10);
	
	for (int i = 0; i < 3; i++)
		first[s[i] - '0']++;
	
	for (int i = 3; i < 6; i++)
		last[s[i] - '0']++;
	
	int ans = 6;
	for (int sum = 0; sum <= 27; sum++) {
		int min_f = 3;
		int min_l = 3;
		for (int i = 0; i <= min(9, sum); i++) {
			vector<int> vals(10);
			vals[i]++;
			for (int j = 0; j <= min(9, sum - i); j++) {
				int z = sum - i - j;
				if (z > 9)
					continue;
				vals[j]++;
				vals[z]++;
				
				int diff_f = 0;
				int diff_l = 0;
				for (int k = 0; k < 10; k++) {
					diff_f += max(0, vals[k] - first[k]);
					diff_l += max(0, vals[k] - last[k]);
				}
				min_f = min(min_f, diff_f);
				min_l = min(min_l, diff_l);
				vals[z]--;
				vals[j]--;
			}
		}
		ans = min(ans, min_f + min_l);
	}
	cout << ans << endl;
	return 0;
}
