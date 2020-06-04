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
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		string val; cin >> val;
		if (val.length() < 3) { cout << "0\n"; continue; }
		vector<int> prefix; prefix.pb(0);
		for (int i = 0; i < val.length(); i++) {
			if (val[i] == '1') { prefix.pb(prefix[i]+1); }
			else { prefix.pb(prefix[i]); }
		}
		int best = min(prefix[(int)val.length()], (int)val.length() - prefix[(int)val.length()]);
		for (int i = 0; i < val.length(); i++) {
			int z = prefix[i+1] + ((int)val.length() - (i+1)) - (prefix[(int)val.length()] - prefix[i+1]);
			int o = (i+1) - prefix[i+1] + prefix[val.length()] - prefix[i+1];
			best = min(best, min(z, o));
		}
		cout << best << endl;
	}
	return 0;
}
