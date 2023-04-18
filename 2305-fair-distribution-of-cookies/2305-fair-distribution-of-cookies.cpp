class Solution {
public:
    
    void func(vector<int>&cookies,int i,int n,int k,vector<int>&container,int &minSum){
        
        if(i==n){
            int currMax = 0;
            for(int j=0;j<k;j++) currMax = max(currMax,container[j]);
            minSum = min(minSum,currMax);
            return;
        }
        
        for(int j=0;j<k;j++){
            container[j] += cookies[i];
            func(cookies,i+1,n,k,container,minSum);
            container[j] -= cookies[i];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>container(k,0);
        int n = cookies.size();
        int minSum = INT_MAX;
        func(cookies,0,n,k,container,minSum);
        return minSum;
    }
};