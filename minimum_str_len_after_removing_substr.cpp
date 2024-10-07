class Solution {
public:
    int minLength(string s) {
        stack<char>stack;
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(stack.empty()){
                stack.push(ch);
                continue;
            }
            if(ch == 'B' && stack.top() == 'A'){
                stack.pop();
            }
            else if(ch ==  'D' && stack.top() == 'C'){
                stack.pop();
            }
            else{
                stack.push(ch);
            }
        }
        return stack.size();
    }
};