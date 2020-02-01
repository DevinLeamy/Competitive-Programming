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

string const v = "aeiou";
string const alp = "abcdefghijklmnopqrstuvwxyz";
char getClosest(char c) {
	int count = alp.find(c); int currentMin = 26; int inc = -1; char returnV = '_';
	for (int i = 0; i < alp.size(); i++) {
		if (alp[i] == c) {inc = 1;}
		if (v.find(alp[i]) != string::npos) {
			if (count < currentMin) {
				returnV = alp[i];
				currentMin = count;
			}
		}
		count += inc;
	}
	return returnV;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string word, output = ""; cin >> word;
	for (int i = 0; i < word.length(); i++) {
		output += word[i];
		if (v.find(word[i]) == string::npos) {
			if (i != 0 && i != word.length()-1) {
				if (v.find(word[i-1]) != string::npos && v.find(word[i+1]) == string::npos) {
					int current = alp.find(word[i-1]) -1;
					while (current > 0) {
						if (v.find(alp[current]) != string::npos){
							break;
						}
						current--;
					}
					if (current == alp.find(word[i-1]) -1 && v.find(alp[current]) == string::npos) {
						output += getClosest(word[i]);
					}
				} else {
					output += getClosest(word[i]);
				}
			} else {
				output += getClosest(word[i]);
			}
			if (word[i] == 'z') {output += 'z';}
			else {
				int current = alp.find(word[i]) + 1;
				while (v.find(alp[current]) != string::npos) {
					current++;
				}
				output += alp[current];
			}
		}
	}
	cout << output << endl;
	return 0;
}
