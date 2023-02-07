class DSU{
  
  public:
  
  vector<int>Parent;
  vector<int>Size;
  
  DSU(int n){
      Parent.resize(n);
      Size.resize(n);
      for(int i=0;i<n;i++){
          Parent[i] = i;
          Size[i] = 1;
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
      int lx = find(x);
      return Size[lx];
  }  
    
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU obj(n);
        unordered_map<int,vector<int>>row;
        unordered_map<int,vector<int>>col;
        for(int i=0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        int totalRemoval = 0;
        for(auto &itr : row){
            int leader = itr.second[0];
            for(auto &ele : itr.second){
                obj.Union(leader,ele);
            }
        }
        for(auto &itr : col){
            int leader = itr.second[0];
            for(auto &ele : itr.second){
                obj.Union(leader,ele);
            }
        }
        for(int i=0;i<n;i++){
            if(obj.find(i) == i){
                totalRemoval += (obj.getSize(i) - 1);
            }
        }
        return totalRemoval;
    }
};