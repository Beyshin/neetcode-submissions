class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned_str = "";

        for(const char c : s){
            if(isalpha(c) || isdigit(c)) cleaned_str += tolower(c);
        }

        //cout << cleaned_str << endl;

        int l = 0, r = cleaned_str.length()-1;

        while(l<=r){
            cout << "Comparing " << cleaned_str[l] << " with " << cleaned_str[r] << "." << endl;
            if(cleaned_str[l] == cleaned_str[r]){ 
                l++;
                r--;
                continue;
            }
            else return false;
        }

        return true;
    }
};
