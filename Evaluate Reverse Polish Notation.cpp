class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int res = 0;
        if (!tokens.size())
            return res;
        stack<int> mystk;
        for (int i = 0;i < tokens.size();i++)
        {
            if (isdigit(tokens[i][0]) || tokens[i].size() > 1) // 小心负数
            {
                int num = changeVal(tokens[i]);
                mystk.push(num);
            }
            else
            {
                char oper = tokens[i][0];
                int num2 = mystk.top();
                mystk.pop();
                int num1 = mystk.top();
                mystk.pop();
                int tmp;
                switch (oper)
                {
                    case '+' : tmp = num1 + num2;
                               break;
                    case '-' : tmp = num1 - num2;
                               break;
                    case '*' : tmp = num1 * num2;
                               break;
                    case '/' : tmp = num1 / num2;
                               break;
                }
                mystk.push(tmp);
            }
        }
        return mystk.top();
    }
    int changeVal(string &tar)
    {
        int sum = 0;
        int start = 0;
        int flag = 1;
        if (tar[0] == '-')
        {
            start = 1;
            flag = -1;
        }
        for (int i = start;i < tar.size();i++)
        {
            sum = sum * 10 + (tar[i] - '0');
        }
        return sum * flag;
    }
};