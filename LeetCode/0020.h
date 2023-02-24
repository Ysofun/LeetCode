#pragma once
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (stk.empty() || stk.top() != '(') { return false; }
                else { stk.pop(); }
            }
            else if (s[i] == ']')
            {
                if (stk.empty() || stk.top() != '[') { return false; }
                else { stk.pop(); }
            }
            else if (s[i] == '}')
            {
                if (stk.empty() || stk.top() != '{') { return false; }
                else { stk.pop(); }
            }
            else { stk.push(s[i]); }
        }

        return stk.empty();
    }
};