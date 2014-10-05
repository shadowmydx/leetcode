class Solution {
public:
    /*
    对于两个字符串：
    1、开始割
    2、穷举该结点交换/不交换的结果
    3、递归
    4、注意——要进行剪枝预处理。如果割出的子树的排序结果和结果子树不一样，那么不递归。
    */
    bool isScramble(string s1, string s2) {
        return findScra(s1,s2);
    }
    bool findScra(string s1,string s2)
    {
        if (s1 == "")
            return true;
        int len = s1.length();
        if (len == 1)
            return s1[0] == s2[0] ? true : false;
        bool left = false,right = false;
        string tmp1,tar1,tmp2,tar2;
        for (int i = 1;i < len;i++)
        {
            
            tmp1 = s1.substr(0,i);
            tar1 = s2.substr(0,i);
            tmp2 = s1.substr(i);
            tar2 = s2.substr(i);
            sort(tmp1.begin(),tmp1.end());
            sort(tar1.begin(),tar1.end());
            if (tmp1 != tar1)
                goto START;
            sort(tmp2.begin(),tmp2.end());
            sort(tar2.begin(),tar2.end());
            if (tmp2 != tar2)
                goto START;
            
            left = isScramble(s1.substr(0,i),s2.substr(0,i));
            if (left == true)
            {
                right = isScramble(s1.substr(i),s2.substr(i));
                if (right == true)
                    return true;
            }
START:
            tmp1 = s1.substr(i);
            tar1 = s2.substr(0,len - i);
            tmp2 = s1.substr(0,i);
            tar2 = s2.substr(len - i);
            sort(tmp1.begin(),tmp1.end());
            sort(tar1.begin(),tar1.end());
            if (tmp1 != tar1)
                continue;
            sort(tmp2.begin(),tmp2.end());
            sort(tar2.begin(),tar2.end());
            if (tmp2 != tar2)
                continue;
                
            left = isScramble(s1.substr(i),s2.substr(0,len - i));
            if (left == true)
            {
                right = isScramble(s1.substr(0,i),s2.substr(len - i));
                if (right == true)
                    return true;
            }
        }
        return false;
    }
};