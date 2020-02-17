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
	int n; string s; cin >> n >> s;
	string output = ""; output += s[0];
	int lastIndex = s[0];
	for (int i = 1; i < n; i++) {
		int index = s[i];
		if (index <= lastIndex) {
			output = s[i] + output;
			lastIndex = index;
		} else {
			output += s[i];
		}
	}
	cout << output << endl;
	
	return 0;
}
