class Solution {
public:
    bool isValid(string s) {
        stack<char> mystk;
        int len  = s.size();
        for (int i = 0;i < len;i++)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (mystk.empty())
                    return false;
                char c = mystk.top();
                if (c == '(' && s[i] == ')')
                    mystk.pop();
                else if (c == '[' && s[i] == ']')
                    mystk.pop();
                else if (c == '{' && s[i] == '}')
                    mystk.pop();
                else 
                    return false;
            }
            else
            {
                mystk.push(s[i]);
            }
        }
        if (mystk.empty())
            return true;
        return false;
    }
};