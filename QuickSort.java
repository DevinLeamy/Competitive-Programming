public class QuickSort
{
    public void quickSort(long[] list, long left, long right)
    {
        if (left < right)
        {
            long pivot = partition(list, left, right);
            quickSort(list, left, pivot-1);
            quickSort(list, pivot+1, right);
        }
    }
    private static long partition(long[] list, long left, long right)
    {
        long pivotElement = list[(int) left];
        long leftBound = left, rightBound = right;
        long temp;

        while (left < right)
        {
            while (list[(int)left] <= pivotElement && left < right)
            {
                left++;
            }
            while (list[(int)right] > pivotElement)
            {
                right--;
            }
            if (left < right)
            {
                temp = list[(int) left];
                list[(int)left] = list[(int)right];
                list[(int)right] = temp;
            }
        }
        list[(int)leftBound] = list[(int)right];
        list[(int)right] = pivotElement;
        return right;
    }
}
