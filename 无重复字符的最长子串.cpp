
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ch[256]={0};
        int l=0,r=-1;
        int res=0;
    
        while(l<s.size())
       {
          if(r+1<s.size() && ch[s[r+1]]==0)
          {
              r++;
              ch[s[r]]++;
          }
           else{
               ch[s[l]]--;
               l++;
           }
           res=max(res,r-l+1);
       }
        return res;
    }
};

