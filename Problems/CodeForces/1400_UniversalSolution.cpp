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
	int n; cin >> n;
	loop(n) {
		string s; cin >> s;
		int rock = 0;
		int paper = 0;
		int sis = 0;
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == 'R') { rock++; }
			else if (s[i] == 'P') { paper++; }
			else { sis++; }
		}
		for (int i = 0; i < s.length(); i++) {
			if (rock >= paper && rock >= sis) {
				cout << "P";
			} else if (paper >= rock && paper >= sis) {
				cout << "S";
			} else {
				cout << "R";
			}
		}
		cout << "\n";
	}
	return 0;
}
