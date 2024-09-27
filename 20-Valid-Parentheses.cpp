class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {
            {')', '('}, {'}', '{'}, {']', '['}};
        stack<char> stack;

        for (char ch : s) {
            if (brackets.count(ch)) {
                if (stack.empty() || stack.top() != brackets[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(ch);
            }
        }

        return stack.empty();
    }
};