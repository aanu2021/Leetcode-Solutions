class Solution {
public:
    
    int func(vector<int>&nums,int n,int k){
        
        unordered_map<int,int>freq;
        int ans = 0;
        int l=0,r=0,cnt=0;
        
        while(r<n){
            if(freq[nums[r]]==0) cnt++;
            freq[nums[r]]++;
            while(l<=r && cnt > k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0) cnt--;
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        
        return ans;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        return func(nums,n,k) - func(nums,n,k-1);
        
    }
};

/*

1 2 1 2 3

k = 2
n = 5

1             1
1 2
1 2 1
1 2 1 2
2             2
2 1
2 1 2
1             1
1 2
2             2
2 3
3             3

-----------------------------------------

1              1
1 2            1 2
1 2 1          1 2 1
1 2 1 3

2              2
2 1            2 1
2 1 3          

1              1  
1 3            1 3 
1 3 4    

3              3  
3 4            3 4

4              4

Formulae :

# of Subarrays with K Different integers = 
# of subarrays with atmost K Different integers -
# of subarrays with atmost K-1 Different integers

*/