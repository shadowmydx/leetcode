class Solution {
public:
    /*
    定义分界点：为数组中最大值。
    数组以分界点为界限分别有序。
    0、求出分界点序号
    1、判断target属于哪个区间
    2、进行binarysearch
    */
    int search(int A[], int n, int target) {
        int index;
        if (A[0] < A[n-1])
            index = -1;
        else
            index = findMid(A,0,n-1);
        if (index == -1)
            return binarySearch(A,0,n-1,target);
        else 
        {
            if (target == A[index])
                return index;
            if (target >= A[0])
                return binarySearch(A,0,index,target);
            else
                return binarySearch(A,index+1,n-1,target);
        }
    }
    
    int binarySearch(int A[],int start,int fin,int target)
    {
        if (start > fin)
            return -1;
        int mid = (start + fin) / 2;
        if (A[mid] == target)
            return mid;
        if (A[mid] > target)
            return binarySearch(A,start,mid-1,target);
        else
            return binarySearch(A,mid+1,fin,target);
    }
    
    int findMid(int A[],int start,int fin)
    {
        if (A[start] < A[fin])
            return fin; 
        if (start == fin)
            return fin;
        int mid = (start + fin) / 2;
        if (A[start] < A[mid])
            return findMid(A,mid,fin); // 由于mid自己可能就是分界点（最大值），所以不能排除.
        else if (start == mid)
            return mid;
        else
            return findMid(A,start,mid-1);
    }
};