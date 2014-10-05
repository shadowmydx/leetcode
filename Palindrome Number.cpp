class Solution {
public:
    bool isPalindrome(int x) {
        /*
        思路：每次从个位获取一个数，构建一个新的整数
        */
        if (x < 0)
            return false;
        int y = 0;
        int tmp = x;
        while (tmp)
        {
            y *= 10;
            int num = tmp % 10;
            y += num;
            tmp /= 10;
        }
        if (y == x)
            return true;
        return false;
    }
};