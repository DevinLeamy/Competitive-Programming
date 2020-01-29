#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int> &vect, int low, int high) {
	int pivot = vect[low];
	int leftBound = low+1;
	
	for (int i = low+1; i < high; i++) {
		if (vect[i] < pivot) {
			int temp = vect[i];
			vect[i] = vect[leftBound];
			vect[leftBound] = temp;
			leftBound++;
			
		}
	}
	vect[low] = vect[leftBound-1];
	vect[leftBound-1] = pivot;
	return leftBound-1;
}

void quickSort(vector<int> &vect, int low, int high) {
	if (low < high) {
		int pivot_location = partition(vect, low, high);
		quickSort(vect, low, pivot_location);
		quickSort(vect, pivot_location+1, high);
	}
}
int main() {
	vector<int> values;
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {cin >> v; values.push_back(v);}
	quickSort(values, 0, values.size());
	for (int val : values) {
		cout << val << endl;
	}
}
