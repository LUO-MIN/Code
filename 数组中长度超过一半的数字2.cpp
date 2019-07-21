class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len=numbers.size();
        int mid = len>>1;
        sort(numbers.begin(),numbers.end());
        int tmp=numbers[mid];
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(numbers[i]==tmp)
            {
                count++;
            }
        }
        if(count>(len/2))
        {
            return tmp;
        }
        return 0;
    }
};