class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int fin   = 0;
        int oil   = 0; // 带入的油
        int tmpoil = 0;
        int len = gas.size();
        if (fin == lastPos(start,len))
            return gas[0] >= cost[0] ? 0 : -1;
        do
        {

            int tmpfin = fin; // 我在tmpfin能前进吗？
            while (tmpfin != lastPos(start,len) && ((tmpoil = walk2next(oil,tmpfin,gas,cost))) >= 0)
            {
                tmpfin = nextPos(tmpfin,len);
                oil = tmpoil;
            }
            if (tmpfin == lastPos(start,len))
                return start;
            fin = tmpfin;
            do
            {
                start = lastPos(start,len);
                if (start == fin)
                    return -1;
                int tmp   = gas[start] - cost[start]; // tmp指的是具体某点0油出发到下一点后的剩余油量
                tmpoil += tmp;
            
            } while (tmpoil < 0);
            oil = tmpoil; // 补到能够进入下一点为止，此时oil为补够了的剩余量
            fin = nextPos(fin,len); // 进入下一点
        } while (fin != start); // 由于进入了下一点，所以为start的话，就成功。
        return start;
    }

    int lastPos(int index,int len)
    {
        if (index == 0)
            return len - 1;
        else
            return index - 1;
    }

    int nextPos(int index,int len)
    {
        return (index + 1) % len;
    }

    int walk2next(int oil,int index,vector<int> &gas,vector<int> &cost) // 带有oil的油量进入index，要走的下个点缺/剩多少油
    {
        int total = oil + gas[index];
        return total - cost[index];
    }
};