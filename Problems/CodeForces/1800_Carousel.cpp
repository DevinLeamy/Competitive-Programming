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

int vals[200005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int q; cin >> q;
	loop(q) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> vals[i];
		bool all_same = true;
		for (int i = 0; i < n - 1; i++)
			all_same &= vals[i] == vals[i + 1];
		
		bool two_cons = false;
		for (int i = 0; i < n; i++)
			two_cons |= vals[i] == vals[(i + 1) % n];
		if (all_same) {
			cout << 1 << endl;
			for (int i = 0; i < n; i++)
				cout << 1 << " ";
			cout << endl;
		} else if (two_cons || n % 2 == 0) {
			cout << 2 << endl;
			if (two_cons && n % 2 == 1) {
				int idx = -1;
				vector<int> colors(n);
				for (int i = 0; i < n; i++) {
					if (vals[i] == vals[(i + 1) % n])
						idx = i;
				}
				colors[idx] = 1;
				colors[(idx + 1) % n] = 1;
				int last = 1;
				for (int i = (idx + 2) % n; i != idx; i = (i + 1) % n) {
					if (last == 2)
						last = 1;
					else
						last = 2;
					colors[i] = last;
				}
				for (int val : colors)
					cout << val << " ";
				cout << endl;
			} else {
				for (int i = 0; i < n; i++)
					cout << ((i % 2 == 0)? 1 : 2) << " ";
				cout << endl;
			}
		} else {
			cout << 3 << endl;
			for (int i = 0; i < n; i++) {
				if (i == n - 1)
					cout << 3 << " ";
				else
					cout << ((i % 2 == 0)? 1 : 2) << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
