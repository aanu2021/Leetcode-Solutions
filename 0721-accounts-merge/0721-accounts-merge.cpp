class DSU{
   private:
    vector<int>Parent;
    vector<int>Rank;
   public: 
     DSU(int n){
         Parent.resize(n);
         Rank.resize(n);
         for(int i=0;i<n;i++){
             Parent[i] = i;
             Rank[i] = 1;
         }
     }
     int find(int x){
         if(Parent[x] == x) return x;
         return Parent[x] = find(Parent[x]);
     }
     void Union(int x, int y){
         int lx = find(x);
         int ly = find(y);
         if(lx != ly){
             if(Rank[lx] > Rank[ly]){
                 Parent[ly] = lx;
             }
             else{
                 Parent[lx] = ly;
                 if(Rank[lx] == Rank[ly]) Rank[lx]++;
             }
         }
     }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        int uid = 0;
        vector<vector<string>>answer;
        
        unordered_map<string,int>eid;
        unordered_map<int,string>etn;
        unordered_map<int,unordered_set<string>>lte;
        
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
            for(int j=1;j<accounts[i].size();j++){
                obj.Union(eid[accounts[i][1]], eid[accounts[i][j]]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                int leader_id = obj.find(eid[accounts[i][j]]);
                lte[leader_id].insert(accounts[i][j]);
            }
        }
        
        for(auto &itr : lte){
            int leader_id = itr.first;
            string name = etn[leader_id];
            vector<string>vec;
            auto it = itr.second;
            for(auto iter : it){
                vec.push_back(iter);
            }
            sort(vec.begin(),vec.end());
            reverse(vec.begin(),vec.end());
            vec.push_back(name);
            reverse(vec.begin(),vec.end());
            answer.push_back(vec);
        }
        
        return answer;
    }
};