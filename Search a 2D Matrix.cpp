class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;
        int n = matrix[0].size();
        int start = 0,fin = m - 1;
        int mid,val;
        while (start <= fin)
        {
            mid = (start + fin) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                start = mid + 1;
            else
                fin   = mid - 1;
        }
        start = 0,fin = n - 1,val = mid;
        if (val && target < matrix[val][0])
            val --;
        while (start <= fin)
        {
            mid = (start + fin) / 2;
            if (matrix[val][mid] == target)
                return true;
            else if (matrix[val][mid] < target)
                start = mid + 1;
            else
                fin   = mid - 1;            
        }
        return false;
    }
};