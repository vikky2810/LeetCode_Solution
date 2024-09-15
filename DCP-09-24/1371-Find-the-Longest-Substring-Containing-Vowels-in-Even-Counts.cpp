class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> state_map;
        int state = 0, max_len = 0;
        state_map[0] = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a')
                state ^= (1 << 0);
            else if (s[i] == 'e')
                state ^= (1 << 1);
            else if (s[i] == 'i')
                state ^= (1 << 2);
            else if (s[i] == 'o')
                state ^= (1 << 3);
            else if (s[i] == 'u')
                state ^= (1 << 4);

            if (state_map.find(state) != state_map.end()) {
                max_len = max(max_len, i - state_map[state]);
            } else {
                state_map[state] = i;
            }
        }

        return max_len;
    }
};