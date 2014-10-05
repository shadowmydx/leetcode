class Solution {
public:
    int numDecodings(string s) {
    int *Array;
    int length = s.size();
    if(length == 0)return 0;
    Array = new int[length];
    for(int i = 0;i < length;i++)
        Array[i] = 0;
    if(s[length-1] != '0')
        Array[length-1] = 1;
    else Array[length-1] = 0;
    if(length >= 2 && s[length-2] != '0')
    {
        if(s[length-1] != '0' && s[length-2] == '1')
            Array[length-2] = 2;
        else if(s[length-2] == '2' && s[length-1] >= '1' && s[length-1] <= '6')
            Array[length-2] = 2;
        else if(s[length-1] == '0' && s[length-2] >= '3')
            Array[length-2] = 0;
        else Array[length-2] = 1;
    }
    else if(length >= 2)
        Array[length-2] = 0;
    for(int i = length - 3;i >= 0;i--)
    {
        if(s[i] == '0')
        {
            Array[i] = 0;
            if(i - 1 >= 0)
                if(s[i-1] > '2' || s[i-1] == 0)
                {
                    Array[0] = 0;
                    break;
                }
                else continue;
            else break;
        }
        else if(s[i] == '2' && s[i+1] <= '6' && s[i+1] >= '1')
            Array[i] = Array[i+1] + Array[i+2];
        else if(s[i] == '1')
            Array[i] = Array[i+1] + Array[i+2];
        else if(s[i] == '2' && s[i+1] == '0')
            Array[i] = Array[i+2];
        else Array[i] = Array[i+1];
    }
    return Array[0];
    }
};