class Solution {
public:
    
    typedef long long ll;
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int>answer;
        int n = spells.size();
        int m = potions.size();
        answer.resize(n,0);
        
        vector<pair<int,int>>spellsArr;
        for(int i=0;i<n;i++){
            spellsArr.push_back({spells[i],i});
        }
        
        sort(spellsArr.begin(),spellsArr.end());
        sort(potions.begin(),potions.end());
        
        int i = n-1;
        int j = 0;
        
        for(i=n-1;i>=0;i--){
            while(j < m && (ll)((ll)spellsArr[i].first*(ll)potions[j]) < success){
                j++;
            }
            answer[spellsArr[i].second] = (m-j);
        }
        return answer;
        
    }
};

// n = 3
// m = 5
// success = 7    

// 1 3 5
// 1 2 3 4 5    

// 5 * x >= 7
// x >= 7/5    