/*

If we can generate the gray code for (n-1) numbers , then it is super simple to generate for (n) numbers.

Algorithm :-> 

Simply generate the sequence for (n-1)-th number and we can make sure that using that sequence we can easily form the n-th number sequence as per our given requirements.

e.g :-

n=1 -> [0,1]
n=2 -> [0,1,3,2]

110 --> 111/100
100 --> 101
101 --> 100
111 --> 101

[0,1,3,2,6,7,5,4]

n=3 -> [0,1,3,2,6,7,5,4]
n=4 -> [0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8]

*/

class Solution {
public:
    vector<int> grayCode(int n) {
        
       if(n==1){
           return {0,1};
       }
        
        vector<int>ans;
        
        ans.push_back(0);
        ans.push_back(1);
        
        for(int i=2;i<=n;++i){
            
            int sz = ans.size();
            
            int num_add = pow(2,i-1);
            
            for(int j=sz-1;j>=0;j--){
                
                ans.push_back(num_add+ans[j]);
                
            }
            
        }
        
        return ans;
        
    }
};
    
    