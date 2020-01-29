#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> values;
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {cin >> v; values.push_back(v);}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n-i; j++) {
			if (values[j] < values[j-1]) {
				int temp = values[j];
				values[j] = values[j-1];
				values[j-1] = temp;
			}
		}
		
	}
	for (int val : values) {
		cout << val << endl;
	}
}
