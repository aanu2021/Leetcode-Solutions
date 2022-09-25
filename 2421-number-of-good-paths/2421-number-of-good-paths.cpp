class Solution {
public:
    
    vector<int>Parent,Rank;
    
    int find(int x){
        
        if(Parent[x]==x) return x;
        
        return Parent[x]=find(Parent[x]);
        
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
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n=vals.size();
        
        Parent.resize(n);
        Rank.resize(n);
        
        for(int i=0;i<n;++i){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        
        map<int,vector<pair<int,int>>>adj;
        
        map<int,vector<int>>values;
        
        for(int i=0;i<edges.size();++i){
            
           int u=edges[i][0],v=edges[i][1];
            
            adj[max(vals[u],vals[v])].push_back({u,v});
            
        }
        
        for(int i=0;i<n;++i){
            
            values[vals[i]].push_back(i);
            
        }
        
        int ans=0;
        
        for(auto x:adj){
            
            int curr_val=x.first;
            
            for(auto y:x.second){
                
                Union(y.first,y.second);
                
            }
            
            map<int,int>cnt;
            
            for(auto y:values[curr_val]){
                
                cnt[find(y)]++;
                
            }
            
            for(auto z1:cnt){
                
                int z=z1.second;
                
                ans+=((z*(z-1))/2);
                
            }
            
        }
        
        return ans+n;
        
    }
};