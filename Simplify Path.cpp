class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        if (path == "")
            return "";
        res.push_back("/");
        int len = path.size();
        for (int i = 0;i < len;i++)
        {
            if (path[i] == '/')
            {
                string tmp = getWord(path,i);
                if (tmp == ".")
                    continue;
                else if (tmp == ".." && res.size() > 1)
                    res.pop_back();
                else if (tmp == "")
                    continue;
                else if (tmp != "..")
                    res.push_back(tmp);
            }
        }
        string fin = "";
        if (res.size() > 0)
            fin = res[0];
        else
            return fin;
        for (int i = 1;i < res.size();i++)
            fin = fin + res[i] + '/';
        if (fin.length() > 1)
            return fin.substr(0,fin.length() - 1);
        else
            return fin;
    }
    string getWord(string &s,int index)
    {
        int len = s.size();
        index ++;
        if (index >= len)
            return "";
        string tmp = "";
        while (index < len && s[index] != '/')
        {
            tmp = tmp + s[index];
            index ++;
        }
        return tmp;
    }
};