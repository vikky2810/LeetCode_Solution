class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        vector<string> phoneMap = {
            \\, \\, \abc\, \def\, \ghi\, \jkl\, \mno\, \pqrs\, \tuv\, \wxyz\
        };
        
        backtrack(0, digits, current, result, phoneMap);
        
        return result;
    }
    void backtrack(int index, const string &digits, string &current, vector<string> &result, const vector<string> &phoneMap) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = phoneMap[digits[index] - '0'];
        
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(index + 1, digits, current, result, phoneMap);
            current.pop_back();
        }
    }
};