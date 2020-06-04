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
		ll a, b; cin >> a >> b;
		int count = 0;
		bool works = true;
		if (a == b) {
			cout << "0" << endl;
			continue;
		}
		if (a > b) {
			while(a > b) {
				if (a % 2 == 0) {
					a /= 2;
					count++;
				} else {
					works = false;
					break;
				}
			}
			if (a == b) {
				cout << (count / 3) + ((count % 3) / 2) + ((count % 3) % 2) << endl;
			} else {
				cout << "-1" << endl;
			}
		} else {
			while (a < b) {
				a *= 2;
				count++;
			}
			if (a == b) {
				cout << (count / 3) + ((count % 3) / 2) + ((count % 3) % 2) << endl;
			} else {
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}
