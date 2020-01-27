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
string good = "IOSHZXN";
bool contains(char c) {loopX(good.length()){if (good[i] == c) {return true;}}return false;}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string v; cin >> v;
	loopX(v.length()) {if (!contains(v[i])){cout << "NO" << endl; return 0;}}
	cout << "YES" << endl;
	return 0;
}
