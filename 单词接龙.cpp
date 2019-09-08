class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        queue<string> q;
        q.push(beginWord);
        int res=1;
        while(!q.empty())
        {
            int nextsize=q.size();
            while(nextsize--){
                string curword=q.front();
                q.pop();
                for(int i=0;i<curword.size();i++)
                {
                    string newword=curword;
                    for(auto ch='a';ch<='z';ch++)
                    {
                        newword[i]=ch;
                        if(!wordDict.count(newword) || visited.count(newword))
                            continue;
                        if(newword==endWord)
                            return res+1;
                        
                        visited.insert(newword);
                        q.push(newword);
                    }
                }
            }
            res++;
        }
        
        return 0;
    }
};