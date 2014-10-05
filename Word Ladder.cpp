class Solution {
public:
    struct node
    {
        string se;
        int len;
    };
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<node> myqueue;
        unordered_set<string> flag; // 标记某个词是否被用过。
        unordered_set<string>::iterator it;
        node p;
        p.len = 1;
        p.se  = start;
        flag.insert(start);
        myqueue.push(p);
        while (!myqueue.empty())
        {
            node tmp = myqueue.front();
            if (tmp.se == end)
            {
                return tmp.len;
            }
            myqueue.pop();
            int len = tmp.se.length();
            string s = tmp.se;
            for (int i = 0;i < len;i++)
            {
                for (int ca = 'a';ca <= 'z';ca++)
                {
                    char now = s[i];
                    if (now == ca)
                        continue;
                    s[i] = ca;
                    it = dict.find(s); // 是否为字典中的词语
                    if (it != dict.end())   // 若是
                    {
                        it = flag.find(s); // 是否已经检查过
                        if (it == flag.end())   // 若没有检查过
                        {
                            flag.insert(s);
                            node he;
                            he.len = tmp.len + 1;
                            he.se = s;
                            myqueue.push(he);
                        }
                    }
                    s[i] = now;
                }
            }
        }
        return 0;
    }
};