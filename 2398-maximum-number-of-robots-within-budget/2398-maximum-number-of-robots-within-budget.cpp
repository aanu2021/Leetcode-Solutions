class Solution {
public:
    
    typedef long long ll;
    
    int maximumRobots(vector<int>& c, vector<int>& d, long long budget) {
        
        int maxLen = 0;
        int n = c.size();
        int l=0, r=0;
        
        ll currsum = 0LL; // stores the running sum of our current range.
        int maxval = 0LL; // stores the maximum element out of all the elements in our current range.
        
        deque<int>q;
        
        while(l<n && r<n){
            
            currsum += (ll)d[r];
            
            while(!q.empty() && c[q.back()] <= c[r]){
                q.pop_back();
            }
            
            q.push_back(r);
            
            maxval = c[q.front()];
            
            while(l<=r && ((ll)maxval + ((r-l+1) * currsum)) > budget){
                currsum -= (ll)d[l];
                
                while(!q.empty() && q.front() <= l){
                    q.pop_front();
                }
                
                if(!q.empty()){
                    maxval = (ll)c[q.front()];
                }else{
                    maxval = 0LL;
                }
                
                l++;
                
            }
            
            maxLen = max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};


/*

goal : maximum number of consecutive robots --> maximize k within
budget

eq..n  : x =  max(c[i]...c[j]) + (j-i+1) * sum(d[i]...d[j])
    
if we expand our subarray's right boundary (j -> j+1)
    
         y = max(c[i]...c[j+1]) + (j-i+2) * sum(d[i]...d[j+1])
    
         it is easy to observe that 
         
         max(c[i]...c[j+1]) >= max(c[i]...c[j])
         sum(d[i]...d[j+1]) >= sum(d[i]...d[j])
    
definitely y >= x

(1) obs..n : by expanding our range , we can increase current cost

similarly , 

if we shrink the left boundary (i -> i+1)
    
       z = max(c[i+1]...c[j]) + (j-i) * sum(d[i+1]...d[j])
    
    it is easily observable that
    
    max(c[i+1]...c[j]) <= max(c[i]...c[j])
    sum(d[i+1]...d[j]) <= sum(d[i]...d[j])
    
(2) obs..n : by shrinking our range , we can decrease current cost


summary : when the length of the current range increases , ass 
cost will be higher , and similarly when the length of the current 
range decreases , ass cost will be lower than previous cost.
    
          All in all , it shows the monotoneous behaviour , that
          is a clear indication to use sliding window approach.
    
    (1) during these approach , we need to calc the running sum of 
    the current interval , that we can easily do using prefix sum.
    
    (2) also we need to calc the max out of all the current 
    elements in the interval (we use a deque to store the maximum
    value of the interval at the top of the DS).
    
*/

/*

Time Complexity  : O(N)
Space Complexity : O(N)

*/