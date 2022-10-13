class Solution {
public:
    
    typedef long long ll;
    
    /* max(a) + k*sum(b) <= budget */
    
    int maximumRobots(vector<int>& a, vector<int>& b, long long budget) {
        
        int n = a.size();
        
        int l = 0, r = 0;
        
        ll currsum = 0LL;
        
        int maxLen = 0;
        
        ll currmax = 0LL;
        
        deque<int>q;
        
        while(l<n && r<n){
            
            currsum += (ll)b[r];
            
            while(!q.empty() && a[q.back()] <= a[r]){
                
                q.pop_back();
                
            }
            
            q.push_back(r);
            
            currmax = a[q.front()];
            
            while(l<=r && (currmax + ((r-l+1) * currsum)) > budget){
                
                while(!q.empty() && q.front() <= l){
                    
                    q.pop_front();
                    
                }
                
                currmax = 0LL;
                
                if(!q.empty()){
                    
                    currmax = a[q.front()];
                    
                }
                
                currsum -= (ll)b[l];
                
                l++;
                
            }
            
            maxLen = max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};