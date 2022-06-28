class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        
        map<char,int>freq;
        
        for(char ch:s){
            freq[ch]++;
        }
        
        vector<bool>visited(n+2,false);
        
        vector<int>v;
        
        for(auto itr:freq){
            
            char curr=itr.first;
            int currf=itr.second;
            
            if(visited[currf]==false){
                visited[currf]=true;
            }
            else{
                v.push_back(currf);
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
        
        for(int i=0;i<v.size();i++){
            
            int curr=v[i];
            
            auto itr=S.lower_bound(curr);
            
            if(itr==S.begin()){
                ans+=curr;
            }
            
            else{
                
                itr--;
                
                ans+=(v[i]-(*itr));
                
                S.erase(itr);
                
            }
            
        }
        
        return ans;
        
    }
};