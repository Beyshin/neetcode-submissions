class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<vector<int>, vector<string>> count_to_strings;

       for (const string& s : strs) {
            vector<int> char_count(26, 0); 
            for (char letter : s) {
                char_count[letter - 'a']++;
            }
            count_to_strings[char_count].push_back(s);
        }
        for (auto& [count, anagram_group] : count_to_strings) {
            ans.push_back(std::move(anagram_group)); 
        }
        
        
        return ans;
    }
};
