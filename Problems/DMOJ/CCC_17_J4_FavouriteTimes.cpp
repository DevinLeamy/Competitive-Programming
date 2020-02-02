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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int h = 12, m = 1, n; cin >> n; ll count = 0;
	while (n > 0) {
		if (m == 0 && h == 12 && n > 720) {count *= (n/720 + 1); n = n % 720;}
		string hours = to_string(h);
		string minutes = to_string(m);
		while (minutes.length() < 2) {minutes = "0" + minutes;}
		if (hours.length() == 1) {
			int a = (hours[0] - '0') - (minutes[0] - '0');
			int b =  (minutes[0] - '0') - (minutes[1] - '0');
			if (a == b) {count++;}
		} else {
			int a = (hours[0] - '0') - (hours[1] - '0');
			int b = (hours[1] - '0') - (minutes[0] - '0');
			int c =  (minutes[0] - '0') - (minutes[1] - '0');
			if (a == b && b == c) {count++;}
		}
		m++; if (m == 60) {m = 0; h++;}
		if (h == 13) {h = 1;}
		n--;
	}
	cout << count << endl;
	
	return 0;
}
