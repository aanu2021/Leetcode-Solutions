class Solution {
public:

    // Prefix Suffix Approach //

    int longestSubarray2(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffix(n,0);
        int num_ones = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1) num_ones++;
            else num_ones = 0;
            suffix[i] = num_ones;
        }
        int maxLen = 0;
        num_ones = 0;
        for(int i=0;i<n;i++){
            int currLen = num_ones + (i+1<n ? suffix[i+1] : 0);
            maxLen = max(maxLen,currLen);
            if(nums[i]==1) num_ones++;
            else num_ones = 0;
        }
        return maxLen;
    }

    // Sliding Window Approach //

    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxLen = 0;
        int l=0, r=0;
        int cnt = 0;
        
        while(r<n){
            
            if(nums[r] == 0) cnt++;
            
            while(l<=r && cnt >= 2){
                if(nums[l]==0) cnt--;
                l++;
            }
            
            maxLen = max(maxLen,r-l);
            r++;
        }
        return maxLen;
    }

    /*

    Say we have a subarray [l...r] and we can skip exactly one element from that subarray .

    Now , one thing we need to observe a subarray that we can 
    consider for our calculation must have atmost one zero.

    why ???

    let's try to understand it with some examples.

    Example 1 : [1,1,1,1,1] --> cnt_zero = 0

    We can delete any of these ones and longest subarray that we can 
    take = currLen - 1 = (r-l+1) - 1 = (r-l)

    Example 2 : [1,1,0,1,1,1] --> cnt_zero = 1

    We need to delete the zero for sure such that after deleting 
    that zero , final subarray contains consecutive ones.

    Example 3 : [1,1,0,1,1,1,0,1] --> cnt_zero = 2

    Now we can not take the subarray after deleting exactly one 
    element , why ??? because even if we delete anyone of the zeroes
     , still the resultant subarray will contain atleast one zero ,
      that means we can't get the sequence of consecutive ones.

    In that scenario we need to shrink our window length from the 
    left boundary (i.e index = l) , and whenever we remove the first
     zero of our subarray ,  then we are left with only one zero , 
     in that scenario , we can take the whole subarray (as discussed
      in example 2).

    Algo : Use a sliding window method , by using two pointers l and 
    r indicating left and right boundary of the subarray , if number
     of zeroes in the subarray >= 2 , then shrink our window size 
     from the left boundary , otherwise take the current length in 
     consideration and move our right boundary(expand the window 
     size for further iptimal answers).

    Time Complexity  : O(N)
    Space Complexity : O(1)

    */

};