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
	vector<int> cities; cities.pb(0); int city;
	for (int i = 1; i <= 4; i++) {cin >> city; cities.pb(city + cities[i-1]);}
	for (int i = 0; i < 5; i++) {
		string output = "";
		for (int j = 0; j < 5; j++) {
			output += to_string(abs(cities[i] - cities[j]));
			output += " ";
		}
		cout << output << endl;
	}
	return 0;
}
