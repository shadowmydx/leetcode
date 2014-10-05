class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dic;
        vector<string> res;
        if (digits == "")
        {
            res.push_back("");
            return res;
        }
        string now = "";
        string s = "abc";
        dic.push_back(" ");
        dic.push_back("");
        
        for (int i = 0;i < 5;i++)
        {
            dic.push_back(s);
            for (int j = 0;j < 3;j++)
                s[j] += 3;
        }
        dic.push_back("pqrs");
        dic.push_back("tuv");
        dic.push_back("wxyz");
        backTravel(dic,res,now,digits);
        return res;
    }
    
    void backTravel(vector<string> &dic,vector<string> &res,string now,string digits)
    {
        int num = digits[0] - '0';
        int len = digits.size();
        for (int i = 0;i < dic[num].size();i++)
        {
            if (len == 1)
            {
                res.push_back(now + dic[num][i]);
            }
            else
            {
                backTravel(dic,res,now + dic[num][i],digits.substr(1));
            }
        }
    }
};