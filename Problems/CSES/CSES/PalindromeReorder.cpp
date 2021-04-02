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

string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	string n; cin >> n;
	
	int l = (int) n.length();
	vector<int> cnt(26);
	for (int i = 0; i < l; i++)
		cnt[n[i] - 'A']++;
	
	bool odd = false;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			if (l % 2 == 0) {
				cout << "NO SOLUTION" << endl;
				return 0;
			} else if (odd) {
				cout << "NO SOLUTION" << endl;
				return 0;
			} else {
				odd = true;
			}
		}
	}
	string res = "";
	for (int i = 0; i < 26; i++) {
		res += string(cnt[i] / 2, alph[i]);
	}
	string rev = res;
	reverse(rev.begin(), rev.end());
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1)
			res += string(1, alph[i]);
	}
	res += rev;
	cout << res << endl;
	
	return 0;
}
