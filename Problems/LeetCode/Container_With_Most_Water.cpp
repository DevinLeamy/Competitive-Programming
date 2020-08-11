class Solution {
public:
    int maxArea(vector<int>& height) {
        int best = 0;
        int lp = 0;
        int rp = height.size() -1;
        while (lp < rp) {
            best = max(best, (rp - lp) * min(height[lp], height[rp]));
            if (height[lp] > height[rp]) {
                rp--;
            } else {
                lp++;
            }
        }
        return best;
    }
    
};
