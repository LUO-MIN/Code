class Solution {
public:
    /*
    思维误区：不需要知道s1的全排列，只需要知道，s2中是否存在s1长度的字符串且每个字符出现的次数相同
    */
    bool checkInclusion(string s1, string s2) {
      //如果s1长度大于s2那么不成立
        if(s1.size()>s2.size())
        {
            return false;
        }
        
        vector<int> res;
        res.resize(256
                   ,0);
        //通过哈希映射，将s1中的字符对应到哈希表中，重复出现的，则++之后对应值大于1
        for(auto &x : s1)
        {
            res[x]++;
        }
        
        //定义两个指针，标记s2，
        int slow=0,fast=0;
        while(fast<s2.size())
        {
            //如果s2[fast]在s1中出现，即对应值大于1
            if(res[s2[fast]]){
                res[s2[fast]]--;
                if(fast-slow==s1.size()-1)
                    return true;
                fast++;
            }
            //走到这里说明fast和slow所对应的元素，在s1中没有
            else if(slow==fast){
                slow++;
                fast++;
            }
            //走到这里说明存在s1中存在，且s2中重复次数大于s1中的字符
            else if(s2[slow]==s2[fast])
            {
                res[s2[slow]]++;
                slow++;
            }
            else{
                while(s2[slow]!=s2[fast])
                {
                    res[s2[slow]]++;
                    slow++;
                }
            }
        }
        return false;
    }
};