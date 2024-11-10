class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX, n = nums.size(), currentOr = 0, left = 0;

        for (int right = 0; right < n; ++right) {
            currentOr |= nums[right];
            while (currentOr >= k) {
                minLength = min(minLength, right - left + 1);
                currentOr ^= nums[left++];
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
