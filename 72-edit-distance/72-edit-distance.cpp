class Solution {
public:
   
    int minDistance(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
       
        vector<int>prev(n+1,0);
        
        prev[0]=0;
        
        for(int i=1;i<=n;++i){
            prev[i]=i;
        }
        
         
        for(int i=1;i<=m;++i){
            
            vector<int>curr(n+1,0);
            
            curr[0]=i;
            
            for(int j=1;j<=n;++j){
                
                if(s1[i-1]==s2[j-1]){
                    
                    curr[j]=prev[j-1];
                    
                }
                else{
                    
                    curr[j]=1+min({prev[j-1],curr[j-1],prev[j]});
                    
                }
                
            }
            
            prev=curr;
            
        }
        
        return prev[n];
        
    }
};