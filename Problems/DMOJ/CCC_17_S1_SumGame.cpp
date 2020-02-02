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
	int current = 0; ll a = 0, b = 0; int n, s; cin >> n;
	vector<int> A; vector<int> B;
	loop(n) {cin >> s; A.pb(s);}
	loop(n) {cin >> s; B.pb(s);}
	loop(n) {a += A[i]; b += B[i]; if (a == b) {current = i+1;}}
	cout << current << endl;
	return 0;
}
