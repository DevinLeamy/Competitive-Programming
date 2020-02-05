#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
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
	int a, b, c, d; cin >> a >> b >> c >> d;
	if (  a == 8 || a == 9 ) {
		if ( b == c ) {
			if (d == 8 || d == 9) {
				cout << "ignore" << endl;
				return 0;
			}
		}
	}
	cout << "answer" << endl;
	return 0;
}
