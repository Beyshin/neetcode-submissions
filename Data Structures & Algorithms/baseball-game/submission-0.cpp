class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;

        for(auto& op : operations){
            if(op == "+"){
                //get one operand remove, get second then add first again + push result
                auto first = st.top();
                st.pop();
                auto second = st.top();
                st.push(first);
                st.push(first + second);
            }else if(op == "D"){
                //get last result and double it + push
                auto last = st.top();
                st.push(2 * last);
            }else if(op == "C"){
                //just remove last result
                st.pop();
            }else{
                //push operand
                st.push(stoi(op));
            }
        }

        while(!st.empty()){
            auto last = st.top();
            st.pop();
            sum += last;
        }

        return sum;

    }
};