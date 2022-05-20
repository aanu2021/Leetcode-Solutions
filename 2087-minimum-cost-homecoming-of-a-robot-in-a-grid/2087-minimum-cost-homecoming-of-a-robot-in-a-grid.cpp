class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rC, vector<int>& cC) {
        
        int m=rC.size();
        int n=cC.size();
        
        int a=startPos[0];
        int b=startPos[1];
        
        int c=homePos[0];
        int d=homePos[1];
        
        if(a==c && b==d){
            return 0;
        }
        
        int ans=0;
        
        if(c>a){
            
            for(int i=a+1;i<=c;i++){
                ans+=rC[i];
            }
            
            if(d>b){
                
                for(int i=b+1;i<=d;i++){
                    ans+=cC[i];
                }
                
            }
            
            else{
                
                for(int i=b-1;i>=d;i--){
                    ans+=cC[i];
                }
                
            }
            
        }
        
        else{
            
            for(int i=a-1;i>=c;i--){
                ans+=rC[i];
            }
            
            if(d>b){
                
                for(int i=b+1;i<=d;i++){
                    ans+=cC[i];
                }
                
            }
            
            else{
                
                for(int i=b-1;i>=d;i--){
                    ans+=cC[i];
                }
                
            }
            
        }
        
        return ans;
        
    }
};