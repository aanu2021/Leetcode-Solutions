class Solution {
public:
    
    void recursion(vector<vector<int>>&requests,vector<int>&indegree,int i,int count,int m,int n,int &maxi){
        
        if(i==m){
            for(int j=0;j<n;j++){
                if(indegree[j]){
                    return;
                }
            }
            maxi = max(maxi,count);
            return;
        }
        
        indegree[requests[i][0]]--;
        indegree[requests[i][1]]++;
        
        recursion(requests,indegree,i+1,count + 1,m,n,maxi);
        
        indegree[requests[i][0]]++;
        indegree[requests[i][1]]--;
        
        recursion(requests,indegree,i+1,count,m,n,maxi);
        
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        int m = requests.size();
        
        vector<int>indegree(n,0);
        
        int maxRequest = 0;
        
        recursion(requests,indegree,0,0,m,n,maxRequest);
        
        return maxRequest;
        
    }
};

/*

we need to form a cycle 

0 -> 1 -> 2 -> 3 -> 0
    
0 -> 0
    
0 -> 1 -> 0
    
m = 16
    
what if we consider this problem as recursion + backtracking

after selecting some particular requests, we need to check whether it is possible or not to ends up with all indegrees as 0, that means all the requests can be fulfilled.
     
*/