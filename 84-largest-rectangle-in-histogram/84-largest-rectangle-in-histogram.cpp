class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>left(n,-1);
        vector<int>right(n,n);
        
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && nums[st.top()]>nums[i]){
                left[st.top()]=i;
                st.pop();
            }
            
//             if(!st.empty()){
//                 left[i]=st.top();
//             }
            
            st.push(i);
            
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && nums[st.top()]>nums[i]){
                right[st.top()]=i;
                st.pop();
            }
            
            // if(!st.empty()){
            //     right[i]=st.top();
            // }
            
            st.push(i);
            
        }
        
//         for(int i=0;i<n;i++){
//             cout<<left[i]<<" ";
//         }cout<<"\n";
        
//         for(int i=0;i<n;i++){
//             cout<<right[i]<<" ";
//         }cout<<"\n";
        
        int maxarea=0;
        
        for(int i=0;i<n;i++){
            
            int currarea=nums[i]*(right[i]-left[i]-1);
            
            maxarea=max(maxarea,currarea);
            
        }
        
        return maxarea;
        
    }
};