#include <iostream>
#include <vector>

using namespace std;

int main() {
   int sum = 0;
   int ignore = 0;
   int DW;
   vector<int> D;
   for (int i = 0; i < 9; i++) {
      cin >> DW;
      D.push_back(DW);
   }
   bool found = false;
   vector<int> fake;
   for (int i = 0; i < 9; i++) {
      for (int j = i+1; j < 9; j++) {
         if (j != i) {
            sum = 0;
            for (int z = 0; z < 9; z++) {
               if (z != j && z != i) {
                  sum += D[z];
               }
            }
            if (sum == 100 && !found) {
               fake.push_back(i);
               fake.push_back(j);
               found = true;
            }
         }
      }
   }
   for (int i = 0; i < 9; i++) {
      if (i != fake[0] && i != fake[1]) {
         cout << D[i] << endl;
      }
   }

   return 0;
}
