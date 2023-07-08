class Solution {
public:
    
    typedef long long ll;
    
    long long putMarbles(vector<int>& W, int k) {
        
        int n = W.size();
        
        ll maxSum = (ll)W[0] + (ll)W[n-1];
        ll minSum = (ll)W[0] + (ll)W[n-1];
        
        k--;
        
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        for(int i=0;i<n-1;i++){
            maxHeap.push(W[i] + W[i+1]);
            minHeap.push(W[i] + W[i+1]);
        }
        
        while(k > 0){
            maxSum += (ll)maxHeap.top(); maxHeap.pop();
            minSum += (ll)minHeap.top(); minHeap.pop();
            k--;
        }
        
        return (maxSum - minSum);
        
    }
};