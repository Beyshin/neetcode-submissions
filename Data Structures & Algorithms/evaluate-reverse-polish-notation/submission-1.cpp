class Solution {
public:
    int eval(int opA, int opB, char operation){
        switch(operation){
            case '+':
                return opA + opB;
            case '-':
                return opA - opB;
            case '/':
                return opA/opB;
            case '*':
                return opA * opB;
        }
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "/" || token == "*"){
                int opB = vals.top();
                vals.pop();
                int opA = vals.top();
                vals.pop();
                int res = eval(opA, opB, token[0]);
                vals.push(res);
            }
            else{
                //handle numbers;
                int operand = stoi(token);
                vals.push(operand);
            }
        }

        return vals.top();
    }
};
