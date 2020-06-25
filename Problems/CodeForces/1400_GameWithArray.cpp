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
	int n, s; cin >> n >> s;
	int diff = s - n;
	if (n == 1 && s-1 > 0) { cout << "YES\n" << s << "\n" << s-1 << endl; return 0; }
	if (diff == 0 || diff < n) { cout << "NO" << endl; return 0; }
	cout << "YES\n" << diff + 1 << " ";
	for (int i = 0; i < n-1; i++) { cout << "1 "; }
	cout << "\n" << diff;
	return 0;
}
