class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                nums[i]*=2;
            }
        }
        
        priority_queue<int>pq;
        
        for(int &ele:nums){
            pq.push(ele);
        }
        
        int mini = INT_MAX;
        
        for(int &ele:nums){
            mini = min(mini,ele);
        }
        
        int ans = INT_MAX;
        
        while(!pq.empty() && pq.top()%2==0){
            
            int ele = pq.top();
            pq.pop();
            ans = min(ans,ele-mini);
            mini = min(mini,(ele/2));
            pq.push(ele/2);
            
        }
        
        if(!pq.empty()){
            ans = min(ans,pq.top() - mini);
        }
        
        return ans;
        
    }
};

    