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
	int a, b, k; cin >> a >> b >> k;

	string val1(2*(a + b), '0');
	string val2(2*(a + b), '0');
	if (b == 0 && k > 0) {
		cout << "No" << endl;
		return 0;
	}
	val1[0] = val2[0] = '1';
	int diff = b - k;
	if (diff == 0) {
		for (int i = 1; i < b - 1; i++) {
			val1[i] = '1';
			val2[i + 1] = '1';
		}
		val1[b - 1] = '1';
		val1[b] = val2[b] = '0';
		val2[b + 1] = '1';
	} else if (diff < 0) {
		for (int i = 1; i < 1 + (b - 2); i++) {
			val1[i] = '1';
			val2[i + 1] = '1';
		}
		val1[1 + (b - 2)] = '1';
		val2[1 + (b - 2) + abs(diff) + 2] = '1';
	} else {
		int rem = abs(diff);
		for (int i = 0; i < rem; i++) {
			val1[i] = val2[i] = '1';
		}
		for (int i = rem; i < rem + (b - rem); i++) {
			val1[i] = '1';
			val2[i + 1] = '1';
		}
	}
	for (int i = a + b; i < val1.length(); i++) {
		if (val1[i] == '1' || val2[i] == '1') {
			cout << "No" << endl;
			return 0;
		}
	}
	val1 = val1.substr(0, b + a);
	val2 = val2.substr(0, b + a);
	PI zeros = { 0, 0 };
	PI ones = { 0, 0 };
	for (int i = 0; i < a + b; i++) {
		if (val1[i] == '0')
			zeros.first++;
		else
			ones.first++;
		
		if (val2[i] == '0')
			zeros.second++;
		else
			ones.second++;
	}
	if (zeros.first == a && zeros.second == a)
		if (ones.first == b && ones.second == b) {
			cout << "Yes" << endl << val1 << endl << val2 << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}
