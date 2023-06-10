class Solution {
public:
    
    typedef long long ll;
    
    ll minSum(ll L,ll ele){
        
        ll currSum = 0LL;
        
        if(ele <= L){
            currSum += ((ele*(ele+1))/2);
            currSum += (L-ele);
        }
        else{
            currSum += ((ele*(ele+1))/2);
            currSum -= (((ele-L)*(ele-L+1))/2);
        }
        
        return currSum;
        
    }
    
    int maxValue(int n, int index, int maxSum) {
        
        ll low = 1LL , high = (ll)maxSum;
        
        ll ans = -1LL;
        
        while(low <= high){
            
            ll mid = (low + high)/2;
            
            ll currSum = minSum((ll)index+1,mid);
            // cout<<currSum<<"\n";
            currSum += minSum((ll)n-index,mid);
            // cout<<currSum<<"\n";
            currSum -= mid;
            
            // cout<<mid<<" "<<currSum<<"\n";
            
            if(currSum <= (ll)maxSum){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        
        return ans;
        
    }
};

/*

3
2
18

low  = 1
high = 18
mid  = 9

L = 3



0 1 2 3
    
n = 4
    
index = 2    
    
maxSum = 6    
    
low = 1 , high = 6
    
mid = 3
    
1 1 2 1  
    
    
    5 8
    5 4 3 2 1 1 1 1
    
    5 3
    
    5 4 3 2 1
    2 1
*/    