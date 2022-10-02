class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int>prefix(n+1,0);
        
        for(int i=0;i<bookings.size();i++){
            
            bookings[i][0]--;
            bookings[i][1]--;
            
            prefix[bookings[i][0]]+=bookings[i][2];
            prefix[bookings[i][1]+1]-=bookings[i][2];
            
        }
        
        for(int i=1;i<=n;++i){
            
            prefix[i] += prefix[i-1];
            
        }
        
        prefix.pop_back();
        
        return prefix;
        
    }
};