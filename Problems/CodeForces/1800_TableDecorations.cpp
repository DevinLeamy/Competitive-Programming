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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	vector<ll> vals(3);
	cin >> vals[0] >> vals[1] >> vals[2];
	sort(vals.rbegin(), vals.rend());
	
	if ((vals[1] + vals[2]) * 2 >= vals[0])
		cout << (vals[0] + vals[1] + vals[2])/3 << endl;
	else
		cout << vals[1] + vals[2] << endl;
	return 0;
}
