class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        n/=3;
        sort(piles.begin(),piles.end());
        
        int sum=0;
        
        for(int i=n;i<piles.size();i+=2){
            sum+=piles[i];
        }
        
        return sum;
    }
};