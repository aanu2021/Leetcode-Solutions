class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        
        int n = a.size();
        
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({a[i]+b[i],i});
        }
        
        sort(vec.rbegin(),vec.rend());
        
        int alice = 0,bob = 0;
        int k = 0;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                alice+=a[vec[k].second];
                k++;
            }else{
                bob+=b[vec[k].second];
                k++;
            }
        }
        
        if(alice>bob) return 1;
        else if(alice<bob) return -1;
        else return 0;
        
    }
};