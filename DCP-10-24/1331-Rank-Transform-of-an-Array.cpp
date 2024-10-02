class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v (arr);
        std::ranges::sort(v);
        unordered_map<int,int> rk;

        for(int a : v)
        {
            if(!rk.count(a))
            {
                rk[a] = rk.size() + 1;
            }
        }

        for(int& a : arr)
        {
            a = rk[a];
        }
        return arr;
    }
};