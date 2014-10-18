class Solution {
public:
    int findMin(vector<int> &num) {
        return trueStuff(num,0,num.size() - 1);
    }
    int trueStuff(vector<int> &num,int start,int fin)
    {
        if (start == fin)
            return num[start];
        if (num[start] < num[fin])
            return num[start];
        int mid = (start + fin) / 2;
        if (start == mid)
            return num[start + 1];
        if (num[start] < num[mid])
            return trueStuff(num,mid,fin);
        if (num[start] > num[mid])
        {
            if (num[mid-1] > num[mid])
                return num[mid];
            return trueStuff(num,start,mid);
        }
    }
};