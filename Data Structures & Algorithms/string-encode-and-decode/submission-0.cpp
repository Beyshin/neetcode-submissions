class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";

        for(const string& str : strs){
            output += to_string(str.length()) + "#" + str;
        }
        cout << output << endl;
        return output;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.length()){
            size_t delimiter_pos = s.find('#', i);

            int len = stoi(s.substr(i, delimiter_pos - i));
            string word = s.substr(delimiter_pos + 1, len);

            ans.push_back(word);

            i = delimiter_pos+len+1;
        }

        return ans;
    }
};
