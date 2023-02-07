class DSU{
  
  public:
  
  vector<int>Parent;
  vector<int>Rank;
  
  DSU(int n){
      Parent.resize(n);
      Rank.resize(n);
      for(int i=0;i<n;i++){
          Parent[i] = i;
          Rank[i] = 1;
      }
  }
  
  int find(int x){
      if(Parent[x]==x) return x;
      return Parent[x] = find(Parent[x]);
  }
  
  void Union(int x,int y){
      int lx = find(x);
      int ly = find(y);
      if(lx != ly){
          if(Rank[lx] < Rank[ly]){
              Parent[lx] = ly;
          }
          else{
              Parent[ly] = lx;
              if(Rank[lx] == Rank[ly]){
                  Rank[lx]++;
              }
          }
      }
  }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // store the final user to email groups
        vector<vector<string>>ans;
        int uid = 0;
        // unique email id for emails
        unordered_map<string,int>eid;
        // email corresponding to their users
        unordered_map<int,string>etn;
        int n = accounts.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(eid.find(accounts[i][j]) == eid.end()){
                    eid[accounts[i][j]] = uid++;
                    etn[eid[accounts[i][j]]] = accounts[i][0];
                }
            }
        }
        
        DSU obj(uid);
        
        for(int i=0;i<n;i++){
            string user = accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                obj.Union(eid[accounts[i][1]],eid[accounts[i][j]]);
            }
        }
                              
        // Leader to Emails                      
        unordered_map<int,unordered_set<string>>lte;
                            
        for(int i=0;i<n;i++){
            string user = accounts[i][0];
            int leader_id = obj.find(eid[accounts[i][1]]);
            for(int j=1;j<accounts[i].size();j++){
                lte[leader_id].insert(accounts[i][j]);
            }
        }
                              
        
        for(auto &itr : lte){
            int leaderValue = itr.first;
            string user = etn[leaderValue];
            vector<string>vec;
            for(auto &it : itr.second){
                vec.push_back(it);
            }
            sort(vec.begin(),vec.end());
            reverse(vec.begin(),vec.end());
            vec.push_back(user);
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
        }       
        return ans;                      
    }
};