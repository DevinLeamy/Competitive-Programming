#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
   int N;
   cin >> N;
   unordered_map<string, int> map;
   for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      map[S]++;
      int V = map[S];
      if (V > 1) {
         cout << S << (V-1) << endl;
      } else {
         cout << "OK" << endl;
      }
   }
   return 0;
}
