class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> char_count(26, 0);
        vector<vector<string>> ans;

        map<vector<int>, vector<int>> vector_to_index;

        for(int idx = 0; idx<strs.size(); idx++){
            for(const auto letter : strs[idx]){
                char_count[letter - 'a']++;
            }

            cout << strs[idx] << endl;

            for(int i = 0; i<char_count.size(); i++){
                char c = i + 'a';
                //cout << c << ": " << char_count[i] << endl;
            }

            vector_to_index[char_count].push_back(idx);

            fill(char_count.begin(), char_count.end(), 0);
        }

        for(auto [k,v] : vector_to_index){
            vector<string> anagrams;
            for(auto idx : v){
                anagrams.push_back(strs[idx]);
            }
            ans.push_back(anagrams);
        }
        
        return ans;
    }
};
