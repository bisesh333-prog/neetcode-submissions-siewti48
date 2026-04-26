class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        int range = maxVal - minVal + 1;
        vector<int> freq(range, 0);

        // count frequency
        for (int num : nums) {
            freq[num - minVal]++;
        }

        // traverse from largest to smallest
        for (int i = range - 1; i >= 0; i--) {
            k -= freq[i];
            if (k <= 0) {
                return i + minVal;
            }
        }

        return -1;
    }
};
