class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanMap = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;
        int prevValue = 0;

        for (char c : s) {
            int currentValue = romanMap[c];
            if (currentValue > prevValue) {
                total += currentValue - 2 * prevValue;
            } else {
                total += currentValue;
            }
            prevValue = currentValue;
        }
        return total;
    }
};