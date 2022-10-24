class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[2] < y[2];
    }
    
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
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        vector<bool>ans(queries.size(),false);
        
        Parent.resize(n,0);
        Rank.resize(n,0);
        
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(edgeList.begin(),edgeList.end(),comp);
        sort(queries.begin(),queries.end(),comp);

        int j=0;
        
        for(int i=0;i<queries.size();i++){
            
            while(j<edgeList.size() && edgeList[j][2] < queries[i][2]){
                
                Union(edgeList[j][0],edgeList[j++][1]);
                
            }
            
            int u = find(queries[i][0]);
            int v = find(queries[i][1]);
            
            if(u==v){
                ans[queries[i][3]] = true;
            }else{
                ans[queries[i][3]] = false;
            }
            
        }
        
        return ans;
        
    }
};