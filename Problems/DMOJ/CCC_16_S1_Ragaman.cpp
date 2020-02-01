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

int counter[26];
string alp = "abcdefghijklmnopqrstuvwxyz";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b; int s = 0;
	loop((int)a.length()) {
		int index = (int)alp.find(a[i]);
		counter[index]++;
	}
	loop((int)b.length()) {
		if (b[i] == '*') {s++;}
		else {
			int index = (int)alp.find(b[i]);
			counter[index]--;
		}
	}
	int count = 0; bool works = true;
	loop(26) {
		if (counter[i] < 0) {works = false;}
		count += counter[i];
	}
	if (count != s) {works = false;}
	if (works) {cout << "A" << endl;}
	else {cout << "N" << endl;}
	
	return 0;
}
