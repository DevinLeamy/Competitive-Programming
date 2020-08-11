class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> contains;
        vector<vector<int>> ans;
        int zeros = 0;
        for (int num : nums) {
            contains[num]++;
            if (num == 0) zeros++;
        }
        if (zeros >= 3) {
            ans.push_back({0, 0, 0});
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (auto j = i+1; j < nums.size(); j++) {
                int b = nums[j];
                if (a == 0 && b == 0) continue;
                int sum = a + b;
                int c = -1 * sum;
                if (c < b || !contains[c]) continue; 
                if ((c == a && contains[a] == 1) || (c == b && contains[b] == 1) || (a == b && contains[a] == 1)) continue;
                ans.push_back({a, b, c});
                while (j != nums.size() && nums[j] == b) j++;
                j--;
            }
            while (i != nums.size() && nums[i] == a) i++;
            i--;
        }
        return ans;
    }
};
