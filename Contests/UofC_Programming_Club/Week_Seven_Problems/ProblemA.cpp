#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string date;
    int day;
    cin >> date >> day;
    if ((date == "OCT" && day == 31) || (date == "DEC" && day == 25)) {
        cout << "yup" << endl;
    } else {
        cout << "nope" << endl;
    }
    return 0;
}
