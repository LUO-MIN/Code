class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {

          int i=0;
           int j=1;
           while(i<len&&j<len){
           while(i<len&&arr[i]%2==0)
                          i+=2;
                while(j<len&&arr[j]%2==1)
                         j+=2;
                      if(i<len&&j<len){
                            int temp=arr[i];
                            arr[i]=arr[j];
                            arr[j]=temp;
                        }
            }
}
};