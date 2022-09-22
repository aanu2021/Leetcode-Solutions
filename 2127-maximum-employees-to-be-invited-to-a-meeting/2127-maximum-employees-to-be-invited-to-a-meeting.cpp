class Solution {
public:
    
    vector<vector<int>>r;
    vector<int>m;
    
    int dfs(int u){
        
        if(m[u]!=-1){
            return m[u];
        }
        
        int ans=0;
        
        for(int v:r[u]){
            ans=max(ans,dfs(v));
        }
        
        return m[u]=1+ans;
        
    }
    
    int maximumInvitations(vector<int>& A) {
        
        int n=A.size();
        
        r.resize(n);
        m.resize(n,-1);
        
        int ans1=0,ans2=0;
        
        for(int i=0;i<n;i++){
            r[A[i]].push_back(i);
        }
        
        for(int i=0;i<n;++i){
            
            if(m[i]!=-1){
                continue;
            }
            
            if(A[A[i]]==i){
                
                m[i]=0;
                m[A[i]]=0;
                
                int a=0,b=0;
                
                for(int j:r[i]){
                    
                    if(j==A[i]){
                        continue;
                    }
                    
                    a=max(a,dfs(j));
                    
                }
                
                for(int j:r[A[i]]){
                    
                    if(j==i){
                        continue;
                    }
                    
                    b=max(b,dfs(j));
                    
                }
                
                ans1+=(a+b+2);
                
            }
            
        }
        
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;++i){
            if(visited[i]) continue;
            int j=i;
            int len=0;
            vector<int>store;
            while(!visited[j]){
                store.push_back(j);
                visited[j]=true;
                j=A[j];
            }
            for(int k=0;k<store.size();++k){
                if(store[k]==j){
                    len=store.size()-k;
                    break;
                }
            }
            ans2=max(ans2,len);
        }
     
        return max(ans1,ans2);
        
    }
};