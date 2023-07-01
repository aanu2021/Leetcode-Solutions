class Solution {
public:
    
    void func(vector<int>&cookies,vector<int>&container,int i,int n,int k,int &minOps){
        
        if(i==n){
            int maxSum = 0;
            for(int j=0;j<k;j++){
                maxSum = max(maxSum,container[j]);
            }
            minOps = min(minOps,maxSum);
            return;
        }
        
        for(int j=0;j<k;j++){
            container[j] += cookies[i];
            func(cookies,container,i+1,n,k,minOps);
            container[j] -= cookies[i];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();
        vector<int>container(k,0);
        int minOps = INT_MAX;
        func(cookies,container,0,n,k,minOps);
        return minOps;
        
    }
};