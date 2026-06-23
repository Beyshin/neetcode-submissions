class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_map;
        for(const auto& c : s){
            char_map[c]++;
        }


        for(const auto& c : t){
            char_map[c]--;
        }

        for(auto [k,v] : char_map){
            if(v != 0) return false;
        }

        return true;

    }
};
