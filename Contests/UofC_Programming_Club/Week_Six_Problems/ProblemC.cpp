#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<bool> range(10, false);
   int num;
   string words;
   cin >> num;
   while (num != 0) {
      cin >> words;
      cin >> words;
      if (words == "on") {
         if (range[num-1]) {
            cout << "Stan is dishonest" << endl;
         } else {
            cout << "Stan may be honest" << endl;
         }
         for (int i = 0; i < 10; i++) {
            range[i] = false;
         }
      } else if (words == "low") {
         // range[0] = max(num+1, range[0]);
         for (int i = num-1; i >= 0; i--) {
            range[i] = true;
         }
      } else {
         // range[1] = (min(num -1, range[1]));
         for (int i = num -1; i < 10; i++) {
            range[i] = true;
         }
      }
      cin >> num;
   }

   return 0;
}
