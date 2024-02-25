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
        int MAX = *max_element(nums.begin(),nums.end());
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++) freq[nums[i]]++;
        if(freq[1] > 0){
            if(n == 1) return true;
            else return false;
        }
        DSU obj(MAX+1);
        for(int i=2;i<=MAX;i++){
            int leader = -1;
            for(int j=i;j<=MAX;j+=i){
                if(freq[j] == 0) continue;
                if(leader == -1) leader = j;
                obj.Union(leader, j);
            }
        }
        int leader = -1;
        for(int i=0;i<n;i++){
            int ele = nums[i];
            int pele = obj.find(ele);
            if(leader == -1){
                leader = pele;
            }
            else{
                if(leader != pele) return false;
            }
        }
        return true;
    }
};