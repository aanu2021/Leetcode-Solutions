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
     void Union(int x,int y){
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
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        unordered_map<int,int>indexMap;
        for(int &ele : nums) freq[ele]++;
        if(freq[1] > 0){
            if(n==1) return true;
            else return false;
        }
        vector<int>vec;
        for(auto &itr : freq) if(itr.second > 0) vec.push_back(itr.first);
        for(int i=0;i<vec.size();i++){
            indexMap[vec[i]] = i;
        }
        n = vec.size();
        int MAX = *max_element(vec.begin(),vec.end());
        DSU obj(n);
        for(int i=2;i<=MAX;i++){
            int pidx = -1;
            for(int j=i;j<=MAX;j+=i){
                if(freq[j] == 0) continue;
                int idx = indexMap[j];
                if(pidx == -1) pidx = idx;
                obj.Union(pidx, idx);
            }
        }
        int prevIndex = -1;
        for(int i=0;i<n;i++){
            int idx = indexMap[vec[i]];
            int pidx = obj.find(idx);
            if(prevIndex == -1){
                prevIndex = pidx;
            }
            else{
                if(prevIndex != pidx) return false;
            }
        }
        return true;
    }
};