#include <iostream>
#include <vector>

using namespace std;

int main()
{
   string N;
   cin >> N;
   char highest = N[0];
   for (int i = 0; i < N.length(); i++)
   {
      if (N[i] > highest)
      {
         cout << "Ann" << endl;
      } else {
          highest = N[i];
         cout << "Mike" << endl;
      }
   }

}
