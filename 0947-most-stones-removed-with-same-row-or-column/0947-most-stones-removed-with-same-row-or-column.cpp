class DSU{
   private:
    vector<int>Parent;
    vector<int>Size;
   public:
     DSU(int n){
         Parent = vector<int>(n);
         Size = vector<int>(n);
         for(int i=0;i<n;i++){
             Parent[i] = i;
             Size[i] = 1;
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
             if(Size[lx] > Size[ly]){
                 Size[lx] += Size[ly];
                 Parent[ly] = lx;
             }
             else{
                 Size[ly] += Size[lx];
                 Parent[lx] = ly;
             }
         }
     }
     int getSize(int x){
         int p = find(x);
         return Size[p];
     }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int,vector<int>>rowMap;
        unordered_map<int,vector<int>>colMap;
        DSU obj(n);
        for(int i=0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1];
            rowMap[x].push_back(i);
            colMap[y].push_back(i);
        }
        for(auto &itr : rowMap){
            for(auto &it : itr.second){
                obj.Union(itr.second[0], it);
            }
        }
        for(auto &itr : colMap){
            for(auto &it : itr.second){
                obj.Union(itr.second[0], it);
            }
        }
        int total = 0;
        for(int i=0;i<n;i++){
            int p = obj.find(i);
            if(p == i){
                total += obj.getSize(i) - 1;
            }
        }
        return total;
    }
};