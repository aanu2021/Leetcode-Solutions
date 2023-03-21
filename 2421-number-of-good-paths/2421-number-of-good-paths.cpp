
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
  
  bool Union(int x,int y){
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
          return true;
      }
      else{
          return false;
      }
  }
  
  int getSize(int x){
      int lx = find(x);
      return Size[lx];
  }
    
};


class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        map<int,vector<int>>values;
        map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            values[vals[i]].push_back(i);
        }
        for(int i=0;i<edges.size();++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[max(vals[u],vals[v])].push_back({u,v});
        }
        int ans = n;
        DSU obj(n);
        for(auto &itr : adj){
            int currValue = itr.first;
            for(auto &it : itr.second){
                int u = it.first;
                int v = it.second;
                obj.Union(u,v);
            }
            map<int,int>cnt;
            for(int &ele : values[currValue]){
                cnt[obj.find(ele)]++;
            }
            for(auto &it : cnt){
                int curr = it.second;
                ans += ((curr*(curr-1))/2);
            }
        }
        return ans;
    }
};