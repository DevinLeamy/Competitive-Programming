#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
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
		vector<int> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		bool first = true;
		int last = -1;
		while (true) {
			int largest = -1;
			int index = -1;
			for (int i = 0; i < n; i++) {
				if (vals[i] > 0 && vals[i] > largest && i != last) {
					largest = vals[i];
					index = i;
				}
			}
			if (index == -1) break;
			last = index;
			vals[index]--;
			first = !first;
		}
		if (!first) {
			cout << "T" << endl;
		} else {
			cout << "HL" << endl;
		}
	}
	return 0;
}
