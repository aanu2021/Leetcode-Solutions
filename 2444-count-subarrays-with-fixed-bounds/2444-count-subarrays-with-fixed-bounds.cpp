class Solution {
public:
    
    typedef long long ll;
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int n = nums.size();
        
        int leftObstacle = -1;
        int minPosition = -1;
        int maxPosition = -1;
        
        ll ans = 0LL;
        
        for(int i=0;i<n;i++){
            if(nums[i] < minK || nums[i] > maxK){
                leftObstacle = i;
                continue;
            }
            if(nums[i] == minK){
                minPosition = i;
            }
            if(nums[i] == maxK){
                maxPosition = i;
            }
            ans += (ll)max(0,min(minPosition,maxPosition)-leftObstacle);
        }
        return ans;
    }
};

/*

1 3 5 7 2 5
    
what type of elements we should avoid to pick in our subarray ???
    
ele < minK
ele > maxK

see if we pick them up , then either min(arr[l...r]) < minK or,
                                     max(arr[l...r]) > maxK for sure.
                                         
Now it is quiet obvious that we need to take all the element which are lying in the range [minK,maxK]

For simplicity of the problem we will denote all the elements( < minK || >maxK) as the obstacles that we need to avoid.
                                         
Cool , but there is another super important condition given in the problem , i.e no matter which subarray we consider , the minimum element must be equal to minK and maximum element must be equal to maxK.Again, for simplicity we consider this type of subarrays as good subarrays.
                                         
That clearly signifies that inside our subarray both the min and max elements should be present.
                                         
Let us visualize this problem as follows : 

(Good subarrays ending at index 0) + (Good Subarrays ending at index 1) + (Good Subarrays ending at index 2) + ..... (Good subarrays ending at index n-1).
    

Again it is very very intuitive that , 

0 1 2 3 4 5 6 7 8 9 10 11
        b   m   M       i
        
all possible subarrays ending at index i :

[8,11]
[9,11]
[10,11]
[11,11]

why not other subarrays , see we have to start out journey of starting index after the blockage (or else our subarray becomes bad)
    
so why we are considering starting index from index m(where exactly the minimum element appears) , see we want both of the minimum and maximum elements to be present in our subarray. So we need to take the minimum out of the key points to be satisfied with the good subarray.  
    
*/