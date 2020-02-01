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

bool given[1000001];
bool small[1000001];
bool medium[1000001];
bool large[1000001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int j, a, v; cin >> j >> a; string size; int count = 0;
	loop(j) {
		cin >> size;
		if (size == "S") {small[i+1] = true;}
		else if (size == "M") {medium[i+1] = true;}
		else if (size == "L") {large[i+1] = true;}
	}
	loop(a) {
		cin >> size >> v;
		if (given[v]) {continue;}
		if (size == "S") {
			if (small[v]) {given[v] = true; count++;}
			else if (medium[v]) {given[v] = true; count++;}
			else if (large[v]) {given[v] = true; count++;}
		} else if (size == "M") {
			if (medium[v]) {given[v] = true; count++;}
			else if (large[v]) {given[v] = true; count++;}
		} else {
			if (large[v]) {given[v] = true; count++;}
		}
	}
	cout << count << endl;
	return 0;
}
