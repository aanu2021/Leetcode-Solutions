class Solution {
public:
    
    vector<int>Parent;
    
    vector<int>Rank;
    
    int find(int x){
        
        if(Parent[x]==x){
            return x;
        }
        
        int temp=find(Parent[x]);
        
        return Parent[x]=temp;
        
    }
    
    void Union(int x,int y){
        
        int lx=find(x);
        int ly=find(y);
        
        if(lx!=ly){
            
            if(Rank[lx]<Rank[ly]){
                
                Parent[lx]=ly;
                
            }
            
            else{
                
                Parent[ly]=lx;
                
                if(Rank[lx]==Rank[ly]){
                    
                    Rank[lx]++;
                    
                }
                
            }
            
        }
        
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& R, vector<vector<int>>& edges) {
        
        Parent.resize(n);
        Rank.resize(n);
        
        for(int i=0;i<n;++i){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        vector<bool>ans(edges.size(),false);
        
        for(int i=0;i<edges.size();++i){
            
            int p1=find(edges[i][0]);
            int p2=find(edges[i][1]);
            
            bool flag=true;
            
            for(int j=0;j<R.size();++j){
                
                int pp1=find(R[j][0]);
                int pp2=find(R[j][1]);
                
                if((pp1==p1 && pp2==p2) || (pp1==p2 && pp2==p1))
                {
                    
                    flag=false;
                    break;
                    
                }  
                    
            }
            
            if(flag){
                
                ans[i]=true;
                Union(p1,p2);
                
            }
            
        }
        
        return ans;
        
    }
};