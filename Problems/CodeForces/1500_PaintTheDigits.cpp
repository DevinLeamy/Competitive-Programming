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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		bool flag = true;
		int p1 = 0;
		int p2 = 0;
		vector<int> sV(n);
		sV[n-1] = s[n-1] - '0';
		for (int i = n-2; i >= 0; i--) {
			int val = s[i] - '0';
			sV[i] = min(val, sV[i + 1]);
		}
		string output = "";
		int p2F = INF;
		for (int i = 0; i < n; i++) {
			int val = s[i] - '0';
			if (val <= sV[i] && val <= p2F) {
				p1 = val;
				output += '1';
			} else {
				if (val < p2) {
					flag = false;
				}
				p2 = val;
				if (p2F == INF) {
					p2F = val;
				}
				output += '2';
			}
		}
		if (flag && p2F >= p1) {
			cout << output << "\n";
		} else {
			cout << "-\n";
		}
		
		
	}
	return 0;
}
