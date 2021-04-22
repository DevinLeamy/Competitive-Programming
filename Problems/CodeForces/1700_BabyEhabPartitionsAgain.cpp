#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
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

bool canPartition(vector<PI>& nums) {
	bitset<423456> bits(1);
	int sum = 0;
	for (auto n : nums) {
		sum += n.first;
		bits |= bits << n.first;
	}
	return !(sum % 2) && bits[sum / 2];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<PI> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i].first;
		vals[i].second = i;
	}
	vector<int> ans;
	if (canPartition(vals)) {
		sort(vals.begin(), vals.end());
		for (int i = 0; i < vals.size(); i++) {
			PI temp = vals[i];
			vals.erase(vals.begin() + i);
			if (!canPartition(vals)) {
				ans.pb(temp.second);
				break;
			}
			vals.pb(temp);
			sort(vals.begin(), vals.end());
		}
	}
	cout << ans.size() << endl;
	for (int val : ans)
		cout << val + 1 << " ";
	cout << endl;
	return 0;
}
