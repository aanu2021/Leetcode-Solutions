class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        double low = 0.0 , high = 1.0;
        
        vector<int>ans(2,-1);
        
        while(low<=high){
            
            double mid = (low + high) / 2;
            
            int total = 0;
            
            int i=0,j=0;
            
            double maxf = 0.0;
            
            for(i=0;i<n;i++){
                
                while(j<n && arr[i]>arr[j]*mid){
                    j++;
                }
                
                if(j==n){
                    break;
                }
                
                total+=(n-j);
                
                double frac = ((arr[i]*1.0) / (arr[j]));
                
                if(frac > maxf){
                    maxf = frac;
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                }
                
            }
            
            if(total==k){
                break;
            }
            
            if(total>k){
                high = mid;
            }else{
                low = mid;
            }
            
        }
        
        return ans;
        
    }
};