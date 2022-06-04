class Solution {
public:
    
    int Parent[10005];
    int Rank[10005];
    
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
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for(int i=0;i<=10000;i++){
            Parent[i]=i;
            Rank[i]=1;
        }
        
        
        int uid=0;
        
        unordered_map<string,int>eid;
        unordered_map<string,string>etn;
        
        for(int i=0;i<accounts.size();i++){
            
            string name="";
            
            for(int j=0;j<accounts[i].size();j++){
                
                if(j==0){
                    name=accounts[i][0];
                    continue;
                }
                
                string email=accounts[i][j];
                
                if(eid.find(email)==eid.end()){
                    eid[email]=uid++;
                }
                
                if(etn.find(email)==etn.end()){
                    etn[email]=name;
                }
                
                int id1=eid[accounts[i][1]];
                int id2=eid[accounts[i][j]];
                
                Union(id1,id2);
                
            }
            
        }
        
        
        unordered_map<int,vector<string>>pte;
        
        for(auto itr:etn){
            
            string name=itr.second;
            string email=itr.first;
            
            int id=eid[email];
            
            int p=find(id);
            
            pte[p].push_back(email);
            
        }
        
        
        vector<vector<string>>result;
        
        
        for(auto itr:pte){
            
            int pid=itr.first;
            
            vector<string>emails=itr.second;
            
            string name=etn[emails[0]];
            
            sort(emails.begin(),emails.end());
            
            vector<string>v;
            
            v.push_back(name);
            
            for(string str:emails){
                v.push_back(str);
            }
            
            result.push_back(v);
            
        }
        
        return result;
        
    }
};