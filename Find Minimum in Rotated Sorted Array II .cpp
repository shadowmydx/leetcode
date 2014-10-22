/*
设首节点为C，中结点为A，末尾结点为D，则有：
C <  D ? 返回 C;
C == D ? 找到下一个为C不等的F，递归调用F,D。若不存在F，则返回C
C >  D ? C <  A ? ---> 递归调用A+1，D
         C >  A ? ---> 寻找A之前第一个和A不等的值B，若B > A则返回A，若B < A则递归调用C,B
         C == A ? ---> 递归调用A+1，D
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size();
        return trueStuff(num,0,len - 1);
    }
    
    int trueStuff(vector<int> &num,int start,int fin)
    {
        if (start == fin)
            return num[start];
        if (num[start] < num[fin])
            return num[start];
        if (num[start] == num[fin])
        {
            while (start < fin)
            {
                if (num[start] != num[fin])
                    break;
                start ++;
            }
            if (start == fin)
                return num[start];
            else
                return trueStuff(num,start,fin);
        }
        int mid = (start + fin) / 2;
        if (num[start] < num[mid])
            return trueStuff(num,mid + 1,fin);
        if (num[start] > num[mid])
        {
            int tmp = mid;
            while (num[tmp] == num[tmp-1])
                tmp --;
            tmp --;
            if (num[tmp] > num[mid])
                return num[mid];
            else
                return trueStuff(num,start,tmp);
        }
        if (num[start] == num[mid])
            return trueStuff(num,mid + 1,fin);
    }
};