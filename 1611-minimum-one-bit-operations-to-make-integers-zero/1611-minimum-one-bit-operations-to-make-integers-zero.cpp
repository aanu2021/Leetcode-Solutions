class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        string s="";
        
        int m=n;
        
        if(n==0){
            return 0;
        }
        
        while(m>0){
            
            s+=to_string(m%2);
            m/=2;
            
        }
        
        reverse(s.begin(),s.end());
        
        int len=s.length();
        
        vector<int>cost(len,0);
        
        cost[len-1]=1;
        
        for(int i=len-2;i>=0;i--){
            cost[i]=(2*cost[i+1])+1;
        }
        
        vector<int>toZero(len,0);
        
        vector<int>toOne(len,0);
        
        
        if(s[len-1]=='0'){
            toOne[len-1]=1;
        }
        
        else{
            toZero[len-1]=1;
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