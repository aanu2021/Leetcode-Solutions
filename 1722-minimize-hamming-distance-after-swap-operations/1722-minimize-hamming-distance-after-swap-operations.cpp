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
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& aS) {
        
        int n=source.size();
        
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        map<int,map<int,int>>mp;
        
        for(int i=0;i<aS.size();i++){
            
            Union(aS[i][0],aS[i][1]);
            
        }
        
        for(int i=0;i<n;i++){
            
            int p=find(i);
            
            mp[p][source[i]]++;
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int num=target[i];
            
            int p=find(i);
            
            if(mp[p][num]>0){
                mp[p][num]--;
            }else{
                ans++;
            }
            
        }
        
        return ans;
        
    }
};