#include <iostream>
#include <vector>

using namespace std;

int main() {
   int N;
   long long T;
   cin >> N;
   vector<long long> times;
   for (int i = 0; i < N; i++) {
      cin >> T;
      times.push_back(T);
   }
   sort(times.begin(), times.end());
   long long timePassed = 0;
   int count = 0;
   for (long long num : times) {
      if (num >= timePassed) {
         timePassed += num;
         count++;
      }
   }
   cout << count << endl;

   return 0;
}
