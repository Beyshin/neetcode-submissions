class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;

        for(const char c : s){
            if(c == '(' || c == '{' || c == '['){
                parentheses_stack.push(c);
            }else{
                if(parentheses_stack.empty()) return false;
                char top = parentheses_stack.top();
                switch(c){
                    case ')':
                        if(top == '(') parentheses_stack.pop();
                        else return false;
                        break;
                    case '}':
                        if(top == '{') parentheses_stack.pop();
                        else return false;
                        break;
                    case ']':
                        if(top == '[') parentheses_stack.pop();
                        else return false;
                        break;
                }
            }
        }

        return parentheses_stack.empty();
    }
};
