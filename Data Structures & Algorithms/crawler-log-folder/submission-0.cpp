class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

       for(auto& log : logs){
            if(log == "../"){
                //go back
                if(!st.empty()) st.pop();
            }else if(log == "./"){
                //stay
                continue;
            }else{
                //move to child
                st.push(log);
            }
       }

       return st.size();
    }
};