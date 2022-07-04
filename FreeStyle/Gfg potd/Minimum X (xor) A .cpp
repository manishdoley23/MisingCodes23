//https://practice.geeksforgeeks.org/problems/x-xor-a-is-minimum-and-set-bits-in-x-b/1

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cnt=0;
       for(int i=0;i<32;i++){
           if(b&(1<<i)){
               cnt++;
           }
       }
       int ans=0;
       for(int i=31;i>=0;i--){
           if(cnt==0) break;
           
           if(a&(1<<i)){
               ans+=((int)pow(2,i));
               cnt--;
           }
       }
       for(int i=0;i<32 && cnt>0;i++){
           if(!(a&(1<<i))){
               ans+=((int)pow(2,i));
               cnt--;
           }
       }
       return ans;
   }
};
