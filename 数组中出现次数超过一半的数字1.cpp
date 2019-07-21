class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0)
        {
            return 0;
        }
    int count = 1;
	int tmp = numbers[0];
    int len=numbers.size();
	for (int i = 1; i<len; ++i)
	{
		if (numbers[i] == tmp)
		{
			count++;
		}
		else{
			count--;
		}
		if (count == 0)
		{
			tmp = numbers[i];//因为是出现次数大于n/2的，所以到最后一定会传值到tmp中
			count++;
		}
	}
      count=0;
      for(int i=0;i<len;i++)
      {
          if(numbers[i]==tmp)
              count++;
      }
	
      if(count>(len/2))
      {
          return tmp;
      }
        return 0;
    }
};