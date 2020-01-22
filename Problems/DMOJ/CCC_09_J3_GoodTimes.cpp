#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	vector<int> diff = {0, -300, -200, -100, 0, 100, 130};
	vector<string> places = {"Ottawa", "Victoria", "Edmonton", "Winnipeg", "Toronto", "Halifax", "St. John's"};
	int currentTime;
	cin >> currentTime;
	doH(7) {
		if (i == 6) {
			string time = to_string(currentTime);
			while (time.length() != 4) {time = "0" + time;}
			int hour = stoi(time.substr(0, 2)) + 1;
			int minute = stoi(time.substr(2, 4));
			minute += 30;
			if (minute >= 60) {
				hour++;
				minute = minute % 60;
			}
			cout << to_string(hour) << to_string(minute) << " in " << places[i] << endl;
		} else {
			diff[i] = currentTime + diff[i];
			if (diff[i] < 0) {diff[i] = 2400+diff[i];}
			else {diff[i] = diff[i] % 2400;}
			cout << diff[i] << " in " << places[i] << endl;
		}
	}
	return 0;
}
