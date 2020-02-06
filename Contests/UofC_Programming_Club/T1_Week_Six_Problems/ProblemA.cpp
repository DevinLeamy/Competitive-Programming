#include <iostream>
#include <set>

using namespace std;

int main() {
   int P, N;
   cin >> P >> N;
   string part;
   set<string> parts;
   int day = -1;
   bool found = false;
   for (int i = 0; i < N; i++) {
      cin >> part;
      parts.insert(part);
      if (parts.size() == P && !found) {
         found = true;
         day = i+1;
      }
   }
   if (found) {
      cout << day << endl;
   } else {
      cout << "paradox avoided" << endl;
   }
   return 0;
}
