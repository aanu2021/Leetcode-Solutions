class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        string s="";
        
        if(n==0){
            return 0;
        }
        
        while(n>0){
            
            s+=to_string(n%2);
            n/=2;
            
        }
        
        reverse(s.begin(),s.end());
        
        int len=s.length();
        
        vector<int>cost(len,0);
        vector<int>toZero(len,0);
        vector<int>toOne(len,0);
        
        cost[len-1]=1;
        
        for(int i=len-2;i>=0;i--){
            cost[i]=(2*cost[i+1])+1;
        }
        
        if(s[len-1]=='1'){
            toZero[len-1]=1;
        }else{
            toOne[len-1]=1;
        }
        
        for(int i=len-2;i>=0;i--){
            
            char ch=s[i];
            
            if(ch=='0'){
                
                toZero[i]=min(toZero[i+1],toOne[i+1]+cost[i+1]);
                toOne[i]=min(toZero[i+1]+cost[i],1+toOne[i+1]+cost[i+1]);
                
            }
            
            else{
                
                toZero[i]=min(toZero[i+1]+cost[i],1+toOne[i+1]+cost[i+1]);
                toOne[i]=min(toZero[i+1],toOne[i+1]+cost[i+1]);
                
            }
            
        }
        
        return toZero[0];
        
    }
};