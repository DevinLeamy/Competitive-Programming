#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define for(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int currentSum = 0;
	string num = "9780921418", character;
	for(3) {
		cin >> character;
		num += character;
	}
	for(num.length()) {
		currentSum += (num[i] - '0') * ((i % 2 == 0)? 1 : 3);
	}
	cout << "The 1-3-sum is " << currentSum << endl;
	
	return 0;
}
