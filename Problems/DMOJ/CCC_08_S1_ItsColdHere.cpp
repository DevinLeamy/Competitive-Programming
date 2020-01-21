#include <iostream>

using namespace std;

int main() {
    string cityName, coldestCity;
    int coldestTemp = 201, cityTemp;
    while (true) {
        cin >> cityName >> cityTemp;
        if (cityTemp < coldestTemp) {
            coldestTemp = cityTemp;
            coldestCity = cityName;
        }
        if (cityName == "Waterloo") {break;}
    }
    cout << coldestCity << endl;
    return 0;
}
