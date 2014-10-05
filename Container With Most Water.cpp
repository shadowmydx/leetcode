class Solution {
public:
    int maxArea(vector<int> &height) {
        /*
        方法：两个指针，指向头部和尾部并计算面积，哪个指针指向的值为短板，则移动哪个指针。
        原因：对于短版而言，这是他所能达到的最大面积，故而加以淘汰。
        */
        int min = 0,line;
        int i = 0,j = height.size() - 1;
        while (i < j)
        {
            int bottom = j - i;
            if (height[i] < height[j])
                line = height[i++];
            else if (height[i] > height[j])
                line = height[j--];
            else 
                line = height[i++,j--];
            int area = bottom * line;
            if (min < area)
                min = area;
        }
        return min;
    }
};