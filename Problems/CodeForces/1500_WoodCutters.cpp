#include <iostream>

using namespace std;

int main() {
   int N;
   long long X, H;
   cin >> N;
   long long lastFilled = -1;
   int count = 1;
   long long potential = -1;
   for (int i = 0; i < N; i++) {
      cin >> X >> H;
      if (potential < X && potential > lastFilled) {
         count++;
         lastFilled = potential;
         potential = -1;
      }
      if ((X - H > lastFilled && i != N-1) || (lastFilled < 0 && i != N-1)) {
         count++;
         potential = -1;
      } else {
         potential = X+H;
      }
      lastFilled = X;
   }
   cout << count << endl;
   return 0;
}
