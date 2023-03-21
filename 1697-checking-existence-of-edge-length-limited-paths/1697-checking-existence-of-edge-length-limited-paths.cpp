
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
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[2] < y[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU obj(n);
        int q = queries.size();
        for(int i=0;i<q;i++){
            queries[i].push_back(i);
        }
        sort(edgeList.begin(),edgeList.end(),comp);
        sort(queries.begin(),queries.end(),comp);
        vector<bool>answer(q,false);
        int j = 0;
        int sz = edgeList.size();
        for(int i=0;i<q;i++){
            while(j<sz && edgeList[j][2] < queries[i][2]){
                obj.Union(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            if(obj.find(queries[i][0]) == obj.find(queries[i][1])){
                answer[queries[i][3]] = true;
            }else{
                answer[queries[i][3]] = false;
            }
        }
        return answer;
    }
};