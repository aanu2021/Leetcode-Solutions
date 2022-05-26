class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        
        int n=a.size();
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i]={a[i]+b[i],i};
        }
        
        sort(vec.rbegin(),vec.rend());
        
        bool flag=true;
        
        int alice=0,bob=0;
        
        for(int i=0;i<n;i++){
            
            if(flag==true){
                
                alice+=a[vec[i].second];
                
                flag=false;
                
            }
            
            else{
                
                bob+=b[vec[i].second];
                
                flag=true;
                
            }
            
        }
        
        if(alice>bob){
            return 1;
        }
        
        else if(alice<bob){
            return -1;
        }
        
        else{
            return 0;
        }
        
    }
};