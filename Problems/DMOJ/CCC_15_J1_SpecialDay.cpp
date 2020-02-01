#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int day, month; cin >> month >> day;
	if (day == 18 && month == 2) {
		cout << "Special" << endl;
	} else if (month == 2) {
		if (day < 18) {
			cout << "Before" << endl;
		} else {
			cout << "After" << endl;
		}
	} else if (month > 2) {
		cout << "After" << endl;
	} else {
		cout << "Before" << endl;
	}
	return 0;
}
