class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> prea ;
        for(const int num : nums)
        {
            if(!prea.insert(num).second)
            {
                return true;
            }

        }
        return false;
    }
};