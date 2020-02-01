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
	string time; PI m = {0, 0}; double timeTaken = 0;
	getline(cin, time);
	m.first = stoi( time.substr(0, 3) );
	m.second = stoi( time.substr(3) );
	while (timeTaken != 120) {
		if (m.first < 10 && m.first >= 7) {timeTaken+=0.5;}
		else if (m.first < 19 && m.first >= 15) {timeTaken+=0.5;}
		else {timeTaken++;}
		m.second++;
		if (m.second == 60) {m.second = 0; m.first++;}
		if (m.first == 24) {m.first = 0;}
	}
	string hours = to_string(m.first); string minutes = to_string(m.second);
	while (hours.length() != 2) {hours = "0" + hours;}
	while (minutes.length() != 2) {minutes = "0" + minutes;}
	cout << hours << ":" << minutes << endl;
	return 0;
}
