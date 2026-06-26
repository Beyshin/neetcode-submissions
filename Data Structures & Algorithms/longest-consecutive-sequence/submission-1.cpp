class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen_nums(nums.begin(), nums.end());
        vector<int> considered;

        int max_counter = 0;

        for (int num : seen_nums) {
            if (!seen_nums.contains(num - 1)) {
                int current_num = num;
                int current_streak = 1;

                while (seen_nums.contains(current_num + 1)) {
                    current_num += 1;
                    current_streak += 1;
                }

                max_counter = max(max_counter, current_streak);
            }
        }

        return max_counter;
    }
};
