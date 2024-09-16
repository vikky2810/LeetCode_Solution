class Solution {
public:
    int convertToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const string& time : timePoints) {
            minutes.push_back(convertToMinutes(time));
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;

        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        minDiff = min(minDiff, (minutes[0] + 1440) - minutes.back());

        return minDiff;
    }
};