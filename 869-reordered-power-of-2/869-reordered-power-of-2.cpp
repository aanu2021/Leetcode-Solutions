class Solution {
public:
    
    typedef long long ll;
    
    bool reorderedPowerOf2(int n) {
        
        if(n==0){
            return false;
        }
        
        string initial=to_string(n);
        
        vector<int>initial_freq(10,0);
        
        for(int i=0;i<initial.length();++i){
            initial_freq[initial[i]-'0']++;
        }
        

        
        ll target=(1LL<<31);
        
        for(ll num=1;num<=target;num*=2){
            
            string curr=to_string(num);
            
            vector<int>curr_freq(10,0);
            
            for(int i=0;i<curr.length();++i){
                curr_freq[curr[i]-'0']++;
            }
            
            
            
            bool flag=true;
                        
            for(int i=0;i<10;++i){
                
                if(initial_freq[i]!=curr_freq[i]){
                    flag=false;
                    break;
                }
                
            }
            
            if(flag){
                return true;
            }
            
        }
        
        return false;
        
    }
};


// 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192