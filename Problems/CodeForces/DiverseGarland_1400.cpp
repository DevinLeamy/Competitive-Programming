#include <iostream>
using namespace std;

int main() {
   int N;
   string G;
   cin >> N >> G;
   char current = G[0];
   int count = 0;
   string choices = "BRG";
   for (int i = 1; i < N; i++) {
      if (G[i] == current) {
         for (int j = 0; j < 3; j++) {
            if (choices[j] != current) {
               count++;
               G[i] = choices[j];
               break;
            }
         }
         if (i != N-1) {
            for (int j = 0; j < 3; j++) {
               if (choices[j] != current && choices[j] != G[i+1]) {
                  G[i] = choices[j];
                  break;
               }
            }
         }
      }
      current = G[i];
   }
   cout << count << endl;
   cout << G << endl;
   return 0;
}
