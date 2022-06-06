class Solution {
public:
    
    int Parent[100005];
    int Rank[100005];
    
    int find(int x){
        
        if(Parent[x]==x){
            return x;
        }
        
        int temp=find(Parent[x]);
        
        return Parent[x]=temp;
        
    }
    
    bool Union(int x,int y){
        
        int lx=find(x);
        int ly=find(y);
        
        if(lx!=ly){
            
            if(Rank[lx]<Rank[ly]){
                Parent[lx]=ly;
            }else{
                Parent[ly]=lx;
                if(Rank[lx]==Rank[ly]){
                    Rank[lx]++;
                }
            }
            
            return false;
            
        }
        
        else{
            
            return true;
            
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        
        int extra=0;
        
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        for(int i=0;i<c.size();i++){
            
            bool temp=Union(c[i][0],c[i][1]);
            
            if(temp==true){
                extra++;
            }
            
        }
        
        set<int>st;
        
        for(int i=0;i<n;i++){
            int p=find(i);
            st.insert(p);
        }
        
        int req=st.size();
        
        req--;
        
        if(req<=extra){
            return req;
        }else{
            return -1;
        }
        
    }
};