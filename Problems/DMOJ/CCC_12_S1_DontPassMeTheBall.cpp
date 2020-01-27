#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loopX(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll count = 0; int n; cin >> n;
	for (int i = 1; i < 100; i++) {
		for (int j = i+1; j < 100; j++) {
			for (int k = j+1; k < 100; k++) {
				if (n > k && k > j && j > i) {count++;}
			}
		}
	}
	cout << count << endl;
	return 0;
}
