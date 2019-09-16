public class BinarySearch {
    public int binarySearch(long array[], int left, int right, long probe)
    {
        if (right >= left)
        {
            int mid = left + (right - left) / 2;
            if (array[mid] == probe)
            {
                while (array[mid] == probe && mid < array.length)
                {
                    mid++;
                }
                return mid - 1;
            }
            if (array[mid] > probe)
            {
                return binarySearch(array, left, mid - 1, probe);
            }
            return binarySearch(array, mid + 1, right, probe);
        }
        return -1;
    }
}
