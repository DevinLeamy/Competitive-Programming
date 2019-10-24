#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N;
   cin >> N;
   string stringN;
   vector<int> numbers;
   while (N > 0) {
      stringN = to_string(N);
      string num = "";
      for (int i = 0; i < stringN.length(); i++) {
         if (stringN[i] != '0') {
            num += '1';
         } else {
            num += '0';
         }
      }
      int newNum = stoi(num);
      numbers.push_back(newNum);
      N -= newNum;
   }
   cout << numbers.size() << endl;
   for (int V : numbers) {
      cout << V << " ";
   }

   return 0;
}
