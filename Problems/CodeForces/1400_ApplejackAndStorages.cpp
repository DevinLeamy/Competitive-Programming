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
	int n; cin >> n;
	vector<int> count(100001);
	set<int> twos;
	set<int> fours;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		count[a]++;
		if (count[a] == 2) {
			twos.insert(a);
		} else if (count[a] == 4) {
			fours.insert(a);
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string s; int a; cin >> s >> a;
		if (s == "+") {
			count[a]++;
			if (count[a] == 2) {
				twos.insert(a);
			} else if (count[a] == 4) {
				fours.insert(a);
			}
		} else {
			if (count[a] == 2) {
				twos.erase(a);
			} else if (count[a] == 4) {
				fours.erase(a);
			}
			count[a]--;
		}
		bool works = false;
		for (auto iter = fours.begin(); iter != fours.end(); iter++) {
			int val = *iter;
			PI vals = {-1, -1};
			for (auto iter2 = twos.begin(); iter2 != twos.end(); iter2++) {
				int val2 = *iter2;
				if ((val2 == val && count[val2] >= 6) || (val2 != val && count[val2] >= 2)) {
					if (vals.first == -1) {
						vals.first = val2;
					} else {
						works = true;
						break;
					}
				}
				if ((val2 == val && count[val2] >= 8) || (val2 != val && count[val2] >= 4)) {
					works = true;
					break;
				}
			}
			if (works) break;
		}
		if (works) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
