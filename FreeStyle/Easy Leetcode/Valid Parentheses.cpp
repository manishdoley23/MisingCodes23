//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        // if(s.size() == 1) return 0;
        stack<char> stk1;
        
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stk1.push(s[i]);
            else{
                if(stk1.empty()) return 0;
                else if(stk1.top() == '(' && s[i] != ')' || stk1.top() == '{' && s[i] != '}' || stk1.top() == '[' && s[i] != ']') return 0;
                stk1.pop();
            }
        }
        if(stk1.size()) return 0;
        return 1;
    }
};
