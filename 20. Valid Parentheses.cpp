class Solution {
public:
    bool isValid(string s) {
        stack<char> res; 
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                res.push(s[i]); 
            }
            else if (s[i] == ')'){
                if (res.empty())
                    return false;
                char x = res.top(); 
                if (x != '(')
                    return false; 
                else
                    res.pop();
            }
            else if (s[i] == ']'){
                if (res.empty())
                    return false;
                char x = res.top(); 
                if (x != '[')
                    return false; 
                else
                    res.pop();
            }
            else if (s[i] == '}'){
                if (res.empty())
                    return false;
                char x = res.top(); 
                if (x != '{')
                    return false; 
                else
                    res.pop();
            }
        }
        if (res.empty())
            return true;
        else
            return false; 
    }
};
