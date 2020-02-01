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
	string line; getline(cin, line); int happy = 0; int sad = 0;
	line += " ";
	string current = line.substr(0, 3); string smile = ":-)";
	string sadFace = ":-(";
	for (int i = 3; i < line.size(); i++) {
		if (current == sadFace) {sad++;}
		else if (current == smile) {happy++;}
		current = current.substr(1) + line[i];
	}
	if (happy == 0 && sad == 0) {
		cout << "none" << endl;
	} else if (happy > sad) {
		cout << "happy" << endl;
	} else if (sad > happy) {
		cout << "sad" << endl;
	} else {
		cout << "unsure" << endl;
	}
	return 0;
}
