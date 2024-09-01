class Solution {
public:
    string expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
    if (s.size() == 1) return s;

    string longest = s.substr(0, 1);

    for (int i = 0; i < s.size(); i++) {
        // Check for odd-length palindromes (single character center)
        string p1 = expandAroundCenter(s, i, i);
        if (p1.size() > longest.size()) {
            longest = p1;
        }

        // Check for even-length palindromes (two character center)
        string p2 = expandAroundCenter(s, i, i + 1);
        if (p2.size() > longest.size()) {
            longest = p2;
        }
    }

    return longest;    
    }
};