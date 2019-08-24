class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
        {
            return false;
        }
        if(dict.empty())
        {
            return false;
        }
        //找到字典中最长的单词长度，分割的单词长度一定小于等于最长单词
        /*int maxlength=0;
        unordered_set<string>::iterator it=dict.begin();
        for(;it!= dict.end();it++)
        {
            if((*it).size()>maxlength)
            maxlength=(*it).size();
        }*/
        //用一个布尔类型的数组
        vector<bool> v(s.size()+1,false);
        v[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
               /* if((i-j)>maxlength)
                {
                    break;
                }*/
                //在j+1~i之间只要有一个满足条件，即就能够找到单词
                if(v[j]&& dict.find(s.substr(j,i-j))!=dict.end())
                {
                    v[i]=true;
                    break;
                }
            }
        }
        return v[s.size()];
    }
};