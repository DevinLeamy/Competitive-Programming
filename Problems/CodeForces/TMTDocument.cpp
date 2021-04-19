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

bool solve() {
	int n; cin >> n;
	string s; cin >> s;
	int t_cnt = 0;
	int m_cnt = 0;
	int m_t = 0;
	int t_t = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			t_cnt++;
			t_t++;
			if (m_cnt > 0)
				m_cnt--;
		} else {
			m_t++;
			m_cnt++;
			t_cnt--;
		}
		if (t_cnt < 0 || m_cnt < 0)
			return false;
	}
	if (m_cnt == 0 && t_t == m_t * 2)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
