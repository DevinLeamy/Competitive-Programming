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
	vector<string> words = {"TO", "CCC", "GOOD", "LUCK", "TODAY"};
	int w;
	cin >> w;
	string currentLine = "WELCOME";
	doH(5) {
		if (currentLine.length() + words[i].length() >= w) {
			int j = 0;
			bool found = false;
			while (currentLine.length() < w) {
				if (currentLine[j] == '.') {
					found = true;
					currentLine = currentLine.substr(0, j) + "." + currentLine.substr(j);
					while (currentLine[j] == '.') {
						j++;
						if (j == currentLine.length()) {j -= currentLine.length();}
					}
				} else {
					j++;
					if (j == currentLine.length()) {j -= currentLine.length();}
					if (j == 0 && !found) {
						while (currentLine.length() < w) {
							currentLine += '.';
						}
						break;
					}
				}
			}
			cout << currentLine << endl;
			currentLine = "";
		}
		currentLine = (currentLine == "")? words[i] : currentLine + "." + words[i];
		if (i == 4) {
			int j = 0;
			bool found = false;
			while (currentLine.length() < w) {
				if (currentLine[j] == '.') {
					found = true;
					currentLine = currentLine.substr(0, j) + "." + currentLine.substr(j);
					while (currentLine[j] == '.') {
						j++;
						if (j == currentLine.length()) {j -= currentLine.length();}
					}
				} else {
					j++;
					if (j == currentLine.length()) {j -= currentLine.length();}
					if (j == 0 && !found) {
						while (currentLine.length() < w) {
							currentLine += '.';
						}
						break;
					}
				}
			}
			cout << currentLine << endl;
		}
	}
	return 0;
}
