class Solution {
public:
    
    bool toposort(vector<unordered_set<int>>&al,int i,vector<int>&res,vector<int>&stat){
        
        if(stat[i]!=0){return stat[i]==1;}
        
        stat[i]=2;
        
        for(int v:al[i]){
            if(!toposort(al,v,res,stat)) return false;
        }
        
        stat[i]=1;
        
        res.push_back(i);
        
        return true;
        
    }
    
    vector<int> sortItems(int n, int m, vector<int>& groups, vector<vector<int>>& beforeItems) {
        
        vector<int>res_temp;
        vector<int>res(n);
        
        vector<int>stat(n+2*m);
        
        vector<unordered_set<int>>al(n+2*m);
        
        for(int i=0;i<n;++i){
            
            if(groups[i]!=-1){
                
                al[n+groups[i]].insert(i);
                al[i].insert(n+m+groups[i]);
                
            }
            
            for(auto j:beforeItems[i]){
                
                if(groups[i]!=-1 && groups[i]==groups[j]){
                    
                    al[j].insert(i);
                    
                }
                
                else{
                    
                    int ig = groups[i]==-1 ? i : n+groups[i];
                    int jg = groups[j]==-1 ? j : n+m+groups[j];
                    al[jg].insert(ig);
                    
                }
                
            }
            
        }
        
        
        for(int i=al.size()-1;i>=0;i--){
            
            if(!toposort(al,i,res_temp,stat)){
                
                return {};
                
            }
            
        }
        
        reverse(res_temp.begin(),res_temp.end());
        
        int k=0;
        
        for(int i=0;i<res_temp.size();++i){
            
            if(res_temp[i]<n){
                
                res[k++]=res_temp[i];
                
            }
            
        }
        
        return res;
        
    }
};

