#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, a; cin >> t;
	loop(t) {
		cin >> n; int currentSum = 0; int currentCost = 0; int zeros = 0;
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == 0) {zeros++;}
			currentSum += a;
		}
		if (currentSum != 0 && zeros == 0) {cout << "0" << endl;}
		else if (zeros > 0) {
			if (currentSum >= 0 || currentSum + zeros != 0) {
				cout << to_string(zeros) << endl;
			} else {
				cout << to_string(zeros + 1) << endl;
			}
		} else if (currentSum == 0) {cout << "1" << endl;}
	}
	return 0;
}
