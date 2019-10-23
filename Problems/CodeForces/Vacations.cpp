#include <iostream>

using namespace std;

int main() {
   int N, last, count, current;
   cin >> N;
   count = 0;
   last = -1;
   for (int i = 0; i < N; i++) {
      cin >> current;
      if (current == 3) {
         if (last == 1) {
            current = 2;
         } else if (last == 2) {
            current = 1;
         } else {
            current = -1;
         }
      }
      if ((current == last) && (last == 1 || last == 2)) {
         count++;
         last = -1;
      } else if (current == 0) {
         count++;
         last = -1;
      } else {
         last = current;
      }
   }
   cout << count << endl;
}
