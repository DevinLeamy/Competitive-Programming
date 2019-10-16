#include <iostream>

using namespace std;

long long partition(long long list[], int size, int left, int right)
{
   long long pivotElement = list[(int) left];
   long long leftBound = left, rightBound = right, temp;

   while (left < right)
   {
      while(list[(int) left] <= pivotElement && left < right)
      {
         left++;
      }
      while (list[(int)right] > pivotElement)
      {
         right--;
      }

      if (left < right)
      {
         temp = list[(int)left];
         list[(int)left] = list[(int) right];
         list[(int) right] = temp;
      }
   }
   list[(int)leftBound] = list[(int)right];
   list[(int)right] = pivotElement;
   return right;
}
void quickSort(long long list[], int size, int left, int right)
{
   if (left < right)
   {
      long long pivot = partition(list, size, left, right);
      quickSort(list, size, left, pivot-1);
      quickSort(list, size, pivot + 1, right);
   }
}

int main()
{
   int N;
   cin >> N;
   long long list[N];
   long long E;
   for (int i = 0; i < N; i++)
   {
      cin >> E;
      list[i] = E;
   }
   quickSort(list, N, 0, N-1);
   for (int i = 0; i < N; i++)
   {
      cout << list[i] << endl;
   }

}
