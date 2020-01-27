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
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; string line; cin >> n >> line;
	int a = 0, b = 0;
	loop(n) {
		if (line[i] == 'A') {
			a++;
		} else {
			b++;
		}
	}
	if (a > b) {cout << "A" << endl;}
	else if (b > a) {cout << "B" << endl;}
	else  {cout << "Tie" << endl;}
	return 0;
}
