#include <iostream>
#include <vector>

using namespace std;

bool entered[1000001];
bool inBuilding[1000001];
int main() {
    int n, a;
    cin >> n;
    bool valid = true;
    int countDays = 1;
    string output = "";
    int currentDay = 0;
    int numInBuilding = 0;
    int currentMax = -1;
    vector<int> dayWorkers;
    for (int i = 0; i < n; i++) {
        cin >> a;
        currentMax = max(currentMax, a);
        currentDay++;
        if (a < 0) {
            a = abs(a);
            if (inBuilding[a] && entered[a]){
                entered[a] = true;
                inBuilding[a] = false;
                numInBuilding--;
            } else {
                valid = false;
            }
        } else {
            if (numInBuilding == 0 && i != 0) {
                output += to_string(currentDay-1);
                output += " ";
                countDays++;
                currentDay = 1;
                for (int num : dayWorkers) {
                    entered[num] = false;
                }
                dayWorkers.clear();
            }
            if (!inBuilding[a] && !entered[a]) {
                dayWorkers.push_back(a);
                numInBuilding++;
                entered[a] = true;
                inBuilding[a] = true;
            } else {
                valid = false;
            }
        }
    }
    output += to_string(currentDay);
    if (numInBuilding > 0) {
        valid = false;
    }
    if (valid) {
        cout << countDays << endl;
        cout << output << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
