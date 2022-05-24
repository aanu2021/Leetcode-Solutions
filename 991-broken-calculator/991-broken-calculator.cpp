class Solution {
public:
    int brokenCalc(int x, int y) {
        
        int ans=0;
        
        while(x<y){
            
            if(y%2!=0){
                y++;
            }else{
                y/=2;
            }
            
            ans++;
            
        }
        
        ans+=(x-y);
        
        return ans;
        
    }
};