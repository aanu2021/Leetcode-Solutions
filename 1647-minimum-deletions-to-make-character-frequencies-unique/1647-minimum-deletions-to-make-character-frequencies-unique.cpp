class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        
        map<char,int>mp;
        
        for(char ch:s){
            mp[ch]++;
        }
        
        vector<bool>visited(n+2,false);
        
        vector<int>v;
        
        for(auto itr:mp){
            
            char ch=itr.first;
            int occ=itr.second;
            
            if(visited[occ]==false){
                visited[occ]=true;
            }
            
            else{
                v.push_back(occ);
            }
            
        }
        
        set<int>S;
        
        for(int i=0;i<=n+1;i++){
            if(visited[i]==false){
                S.insert(i);
            }
        }
        
        int ans=0;
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();++i){
            
            int curr=v[i];
            
            auto itr=S.lower_bound(curr);
            
            if(itr==S.begin()){
                ans+=curr;
                continue;
            }
            
            else{
                itr--;
                ans+=(curr-(*itr));
                S.erase(itr);
            }
            
        }
        
        return ans;
        
    }
};