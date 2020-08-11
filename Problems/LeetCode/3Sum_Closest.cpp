class Solution {
public:
    int binarySearch(int left, int right, vector<int>& vals, int x, int target) {
        int mid = (left + right)/2;
        if (left <= right) return min(left, right);
        int f1 = abs(target - (x + vals[left]));
        int f2 = abs(target - (x + vals[mid]));
        if (f1 < f2) {
            return binarySearch(left, mid-1, vals, x, target);
        }
        return binarySearch(mid, right, vals, x, target);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int best = INT_MAX;
        int sum = -1;
        for (int i = 0; i < n-2; i++) {
            int a = nums[i];
            for (int j = i+1; j < n-1; j++) {
                int b = nums[j];
                int rem = a + b;
                int x = binarySearch(j+1, n-1, nums, rem, target);
                int f1 = abs(target - (rem + nums[x]));
                while (x != n-1 && f1 >= abs(target - (rem + nums[x+1]))) {
                    x++;
                    f1 = abs(target - (rem + nums[x]));
                }
                if (best > f1) {
                    best = min(best, f1);
                    sum = a + b + nums[x];              
                }
            }
            if (best == 0) break;
        } 
        return sum;
    }
};
