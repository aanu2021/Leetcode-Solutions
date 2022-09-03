class Solution {
public:
    
    vector<int>ans;
    
    void func(string &num,int n,int k,int prev){
        
        if(n==0){
            
            ans.push_back(stoi(num));
            return ;
            
        }
        
        if(prev==-1){
            
            for(int i=1;i<=9;++i){
                
                num+=(i+'0');
                
                func(num,n-1,k,i);
                
                num.pop_back();
                
            }
            
        }
        
        else{
            
            int curr_dig1=prev+k;
            
            int curr_dig2=prev-k;
            
            if(curr_dig1>=0 && curr_dig1<=9){
                
                num+=(curr_dig1+'0');
                
                func(num,n-1,k,curr_dig1);
                
                num.pop_back();
                
            }
            
            if(curr_dig2>=0 && curr_dig2<=9 && curr_dig2!=curr_dig1){
                
                num+=(curr_dig2+'0');
                
                func(num,n-1,k,curr_dig2);
                
                num.pop_back();
                
            }
            
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        string num="";
        
        func(num,n,k,-1);
        
        return ans;
        
    }
};