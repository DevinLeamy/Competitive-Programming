#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loopX(h) for(int i = 0; i < h; i++)

using namespace std;

string times(char, int);
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<string> icon = {"*x*"," xx","* *"};
	int n; cin >> n;
	for (int i = 0; i < 3; i++) {
		string line = "";
		for (int j = 0; j < 3; j++) {line += times(icon[i][j], n);}
		for (int j = 0; j < n; j++) {cout << line << endl;}
	}
	return 0;
}
string times(char character, int n) {
	string output = "";
	while (n) {output += character;n--;}
	return output;
}
