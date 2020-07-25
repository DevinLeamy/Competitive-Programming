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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string a, b; cin >> a >> b;
		vector<int> ans;
		int topP = (int) a.length() - 1;
		int bottomP = 0;
		bool top = false;
		bool firstIsOne = a[0] == '1';
		for (int i = n - 1; i > 0; i--) {
			bool currentIsOne = false;
			if (top) {
				currentIsOne = a[bottomP] == '0';
			} else {
				currentIsOne = a[topP] == '1';
			}
			if (currentIsOne == (b[i] == '1')) {
				if (top) {
					bottomP++;
				} else {
					topP--;
				}
				continue;
			}
			if (firstIsOne == (b[i] == '1')) {
				ans.pb(1);
			} else {
				firstIsOne = !firstIsOne;
			}
			ans.pb(i + 1);
			if (top) {
				topP--;
			} else {
				bottomP++;
			}
			top = !top;
		}
		if (firstIsOne != (b[0] == '1'))
			ans.pb(1);
		
		cout << ans.size() << " ";
		for (int val : ans)
			cout << val << " ";
		cout << "\n";
	}
	return 0;
}
