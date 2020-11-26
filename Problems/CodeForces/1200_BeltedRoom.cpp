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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		bool ar = false;
		bool al = false;
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') ar = true;
			else if (s[i] == '>') al = true;
			
			int right = i%n;
			int left = i - 1;
			if (left == -1) {
				left = n-1;
			}
			if (s[right] == '-') { count++; }
			else if (s[left] == '-') { count++; }
		}
		if (ar && !al) {
			cout << n << endl;
		} else if (al && !ar) {
			cout << n << endl;
		} else {
			cout << count << endl;
		}
	}
	return 0;
}
