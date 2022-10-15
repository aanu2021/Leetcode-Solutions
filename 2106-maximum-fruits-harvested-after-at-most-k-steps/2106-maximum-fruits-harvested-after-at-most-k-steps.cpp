/*

Sliding Window Approach 

*/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        
        int n = fruits.size();
        
        vector<int>arr(2*k+1,0);
        
        for(int i=0;i<n;i++){
            
            if(fruits[i][0] < (start-k)){
                continue;
            }
            
            if(fruits[i][0] > (start+k)){
                continue;
            }
            
            arr[fruits[i][0]-(start-k)] += fruits[i][1];
            
        }
        
        int maxval = 0;
        
        int left = 0 , right = 0;
        
        for(int i=0;i<=k;i++){
            left+=arr[i];
            right+=arr[i+k];
        }
        
        maxval = max(left,right);
        
        int turn = 1;
        
        int L = arr.size();
        
        for(int i=2;i<=k;i+=2){
            
            right+=arr[k-turn];
            right-=arr[L-1-(i-1)];
            right-=arr[L-1-(i-2)];
                
            left+=arr[k+turn];
            left-=arr[i-1];
            left-=arr[i-2];
            
            maxval = max(maxval,max(left,right));
            
            turn++;
            
        }
        
        return maxval;
        
    }
};
 