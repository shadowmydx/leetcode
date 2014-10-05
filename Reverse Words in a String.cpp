class Solution {
public:
void readAWord(string &word,string &s,int &i)
{
    string tmp;
    word = tmp;
    while(s[i] == ' ' && s[i] != '\0')i++;
    for(;s[i] != ' ' && s[i] != '\0';i++)
        word = word + s[i];
}
void reverseWords(string &s) 
{
    string tmp;
    string word;
    int i = 0;
    while(1)
    {
        readAWord(word,s,i);
        if(word.size() != 0 && tmp.size() == 0)
            tmp = word + tmp;
        else if(word.size() != 0)
            tmp = word + " " + tmp;
        else break;
    }
    s = tmp;
}
};