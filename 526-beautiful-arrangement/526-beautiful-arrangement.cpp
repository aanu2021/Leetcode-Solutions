class Solution {
public:
    
    int func(int i,int n,vector<bool>&visited){
        
        if(i>n){
            return 1;
        }
        
        int ans = 0;
        
        for(int val=1;val<=n;val++){
            if(!visited[val] && (val%i==0 || i%val==0)){
                visited[val] = true;
                ans += func(i+1,n,visited);
                visited[val] = false;
            }
        }
        
        return ans;
        
    }
    
    int countArrangement(int n) {
        
        vector<bool>visited(n+1,false);
        
        int ans = func(1,n,visited);
        
        return ans;
        
    }
};