class Solution {
public:
    /*
    注意：分治可以提升性能。计算x ** (n/2) 即可计算x ** n
    */
    double pow(double x, int n) {
        int flag = 0;
        if (n < 0)
        {
            flag = 1;
            n = -n;
        }
        double res = truePow(x,n);
        return flag == 1 ? 1.0 / res : res;
    }
    double truePow(double x,int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double res = 1.0;
        if (n % 2 == 0)
        {
            res = truePow(x,n/2);
            return res * res;
        }
        res = truePow(x,n/2);
        return res * res * x;
    }
};