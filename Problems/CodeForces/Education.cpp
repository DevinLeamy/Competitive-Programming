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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; ll c;
		cin >> n >> c;
		vector<ll> sal(n);
		vector<ll> pro(n - 1);
		for (int i = 0; i < n; i++)
			cin >> sal[i];
		for (int i = 0; i < n - 1; i++)
			cin >> pro[i];
		// Find fastest time to get to pos[x], forall x
		// Determine days from x
		vector<PL> days(n);
		days[0].first = 0;
		days[0].second = 0;
		for (int i = 1; i < n; i++) {
			ll earn = pro[i - 1] - days[i - 1].second;
			if (earn <= 0) {
				days[i].first = days[i - 1].first + 1;
				days[i].second = days[i - 1].second - pro[i - 1];
				continue;
			}
			ll cnt = (earn / sal[i - 1]) + ((earn % sal[i - 1] == 0)? 0 : 1);
			ll income = cnt * sal[i - 1];
			days[i].first = days[i - 1].first + cnt + 1;
			days[i].second = income - earn;
		}
		ll min = LINF;
		for (int i = 0; i < n; i++) {
			ll cnt = days[i].first;
			ll earn = c - days[i].second;
			if (earn <= 0) {
				min = std::min(cnt, min);
			} else {
				cnt += (earn / sal[i]) + ((earn % sal[i] == 0)? 0 : 1);
				min = std::min(cnt, min);
			}
		}
		cout << min << endl;
		
	}
	return 0;
}
