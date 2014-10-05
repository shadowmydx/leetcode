class Solution {
public:
    int maxProduct(int A[], int n) {
        int product[n];
        vector<int> zero;
        int max;
        product[0] = A[0];
        if (product[0] == 0)
        {
            product[0] = 1;
            zero.push_back(0);
        }
        for (int i = 1;i < n;i++)
        {
            if (A[i] == 0)
            {
                product[i] = 1;
                zero.push_back(i);
            }
            else
            {
                product[i] = A[i] * product[i-1];
            }
        }
        if (zero.size() == 0)
        {
            return countMax(A,product,0,n);
        }
        else
        {
            int max = A[0];
            int start = 0;
            for (int i = 0;i < zero.size();i++)
            {
                //cout << start << " " << zero[i] << " ";
                int tmp = countMax(A,product,start,zero[i]);
                if (max < tmp)
                    max = tmp;
                start = zero[i] + 1;
            }
            if (start < n)  // 关键！！！
            {
                int tmp = countMax(A,product,start,n);
                if (max < tmp)
                    max = tmp;
            }
            return max > 0 ? max : 0;
        }
    }
    int countMax(int A[],int product[],int start,int fin)
    {
        if (start == fin)
            return A[start];
        vector<int> negtive;
        int ptr;
        int len = fin - start;
        int max = A[start];
        for (int i = start;i < fin;i++)
        {
            if (A[i] < 0)
                negtive.push_back(i);
        }
        ptr = negtive.size() - 1; // 指向当前还没遍历过的下一个负数
        len = negtive.size();
        int preneg = 0; // 记录之前有几个负数
        if (negtive.size() & 1) // 奇数个负数
        {
            for (int i = fin - 1;i >= start;i--)
            {
                preneg = len - ptr - 1;
                if (A[i] < 0)
                {
                    if (preneg == 0)
                    {
                        if (A[i] > max)
                            max = A[i];
                    }
                    else
                    {
                        if (preneg & 1)
                        {
                            int tmp = caculateRange(A,product,i,fin);
                            if (tmp > max)
                                max = tmp;
                        }
                        else
                        {
                            //cout << i << " " << negtive[len-1] << endl;
                            int tmp = caculateRange(A,product,i,negtive[len-1]);
                            if (tmp > max)
                                max = tmp;
                        }
                    }
                    ptr --;
                }
                else
                {
                    if (preneg & 1)
                    {
                        int tmp = caculateRange(A,product,i,negtive[len-1]);
                        if (tmp > max)
                            max = tmp;
                    }
                    else
                    {
                        int tmp = caculateRange(A,product,i,fin);
                        if (tmp > max)
                            max = tmp;
                    }
                }
            }
            return max;
        }
        else
            return caculateRange(A,product,start,fin);
    }
    int caculateRange(int A[],int product[],int start,int fin)
    {
        if (start == fin)
            return A[start];
        if (A[start] == 0)
            return 0;
        if (start == 0)
            return product[fin - 1];
        return product[fin - 1] / product[start - 1];
    }
};