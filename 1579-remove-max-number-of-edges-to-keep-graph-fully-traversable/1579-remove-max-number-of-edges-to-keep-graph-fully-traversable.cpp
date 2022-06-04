class Solution {
public:
    
    bool static comp(vector<int>&x,vector<int>&y){
        
        return x[0] > y[0];
        
    }
    
    int find(int x,vector<int>&Parent){
        
        if(Parent[x]==x){
            return x;
        }
        
        int temp=find(Parent[x],Parent);
        
        return Parent[x]=temp;
        
    }
    
    bool Union(int x,int y,vector<int>&Parent,vector<int>&Rank){
        
        int lx=find(x,Parent);
        int ly=find(y,Parent);
        
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
            
            return true;
            
        }
        
        else{
            
            return false;
            
        }
        
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
       vector<int>Parenta(n+1);
       vector<int>Parentb(n+1);
        
        vector<int>Ranka(n+1);
        vector<int>Rankb(n+1);
        
        for(int i=0;i<=n;i++){
            
            Parenta[i]=Parentb[i]=i;
            Ranka[i]=Rankb[i]=1;
            
        }
        
        sort(edges.begin(),edges.end(),comp);
        
        int cnta=1,cntb=1;
        
        int ans=0;
        
        for(int i=0;i<edges.size();i++){
            
            int type=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            
            if(type==3){
                
                bool tempa=Union(u,v,Parenta,Ranka);
                bool tempb=Union(u,v,Parentb,Rankb);
                
                if(tempa==true){
                    
                    cnta++;
                    
                }
                
                if(tempb==true){
                    
                    cntb++;
                    
                }
                
                if(tempa==true || tempb==true){
                    ans++;
                }
                
            }
            
            else if(type==2){
                
                bool tempb=Union(u,v,Parentb,Rankb);
                
                if(tempb==true){
                    cntb++;
                    ans++;
                }
                
            }
            
            else{
                
                bool tempa=Union(u,v,Parenta,Ranka);
                
                if(tempa==true){
                    cnta++;
                    ans++;
                }
                
            }
            
        }
        
        int sz=edges.size();
        
        if(cnta!=n || cntb!=n){
            return -1;
        }else{
            return (sz-ans);
        }
        
    }
};