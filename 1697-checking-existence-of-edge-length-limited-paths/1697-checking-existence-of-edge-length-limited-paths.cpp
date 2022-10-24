class Solution {
public:
    
    vector<int>Parent;
    vector<int>Rank;
    
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
            }else{
                Parent[ly]=lx;
                if(Rank[lx]==Rank[ly]){
                    Rank[lx]++;
                }
            }
        }
    }
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[2] < y[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        int q = queries.size();
        
        Parent.resize(n);
        Rank.resize(n);
        
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        vector<bool>ans(q,false);
        
        for(int i=0;i<q;i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),comp);
        sort(edgeList.begin(),edgeList.end(),comp);
        
        int j=0;
        
        for(int i=0;i<q;i++){
            
            while(j<edgeList.size() && edgeList[j][2] < queries[i][2]){
                
                Union(edgeList[j][0],edgeList[j++][1]);
                
            }
            
            int u = queries[i][0];
            int v = queries[i][1];
            
            int pu = find(u);
            int pv = find(v);
            
            if(pu==pv){
                ans[queries[i][3]] = true;
            }
            
        }
        
        return ans;
        
    }
};