class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        
        vector<int>v(m+n);
        
        int i=0,j=0;
        
        int k=0;
        
        while(i<m && j<n){
            
            if(nums1[i]<=nums2[j]){
                v[k++]=nums1[i++];
            }else{
                v[k++]=nums2[j++];
            }
            
        }
        
        
        while(i<m){
            
            v[k++]=nums1[i++];
            
        }
        
        while(j<n){
            
            v[k++]=nums2[j++];
            
        }
        
        if(k%2!=0){
            
            return (1.0*v[k/2]);
            
        }
        
        else{
            
            return (v[k/2]+v[k/2-1])/2.0;
            
        }
        
    }
};