class Solution {
public:
    bool isValid(string s) {
        if(s=="")
        {
            return true;
        }
        if(s.length()%2!=0)
        {
            return false;
        }
        
        stack<int> stack;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]=='(' || s[i]=='[' || s[i]=='{')
         {
             stack.push(s[i]);
         }
         else
         {
             if(stack.size()==0)
             {
                 return false;
             }
             else if((s[i]==')'&& stack.top()!='(') 
                     || (s[i]==']'&& stack.top()!='[')
                     || (s[i]=='}'&& stack.top()!='{')
                    )
              {
                  return false;
              }
             else
                 stack.pop();
         }
    }
        if(stack.empty())
        {
             return true;
        }
         return false;
    }
};