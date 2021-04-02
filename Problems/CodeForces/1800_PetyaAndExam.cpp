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
		vector<PL> problems;
		int n; ll T, a, b; cin >> n >> T >> a >> b;
		PI cnts = { 0, 0 }; // Number of easy and number of hard problems
		for (int i = 0; i < n; i++) {
			int type; cin >> type;
			if (type == 1) {
				problems.pb(make_pair(-1, b));
				cnts.second++;
			} else {
				problems.pb(make_pair(-1, a));
				cnts.first++;
			}
		}
		for (int i = 0; i < n; i++) {
			ll time; cin >> time;
			problems[i].first = time;
		}
		sort(problems.begin(), problems.end()); // Sort problems by time; increasing
		ll time_taken = 0;
		// Set ans to score if no manditory problems are taken
		ll ans = max(0ll, min((ll)cnts.first, (problems[0].first - 1) / a));
		ans += max(0ll, min((ll) cnts.second, (problems[0].first - 1 - ans * a) / b));
		for (int i = 0; i < n; i++) {
			time_taken += problems[i].second;
			if (problems[i].second == a)
				cnts.first--;
			else
				cnts.second--;
			while (i + 1 < n && problems[i + 1].first <= time_taken) {
				i++;
				time_taken += problems[i].second;
				if (problems[i].second == a)
					cnts.first--;
				else
					cnts.second--;
			}
			ll leave_time = (i + 1 == n)? T : problems[i + 1].first - 1;
			if (time_taken > leave_time)
				break;
			
			ll score = i + 1;
			ll spare_time = leave_time - time_taken;
			
			ll a_problems = min((ll) cnts.first, spare_time / a);
			score += a_problems;
			spare_time -= a * a_problems;
			ll b_problems = min((ll) cnts.second, spare_time / b);
			score += b_problems;
			ans = max(ans, score);
		}
		cout << ans << endl;
	}
	return 0;
}
