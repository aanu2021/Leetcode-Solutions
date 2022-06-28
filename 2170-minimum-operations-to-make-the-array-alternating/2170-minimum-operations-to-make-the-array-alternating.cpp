class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n=nums.size();
        
        int ans=n;
        
        map<int,int>mp;
        
        for(int i=0;i<n;i+=2){
            mp[nums[i]]++;
        }
        
        vector<pair<int,int>>v;
        
        for(auto itr:mp){
            v.push_back({itr.second,itr.first});
        }
        
        sort(v.rbegin(),v.rend());
        
        int a1=-1,a2=-1,fa1=0,fa2=0;
        
        int req1=(n+1)/2;
        int req2=n/2;
        
        int sz=v.size();
        
        if(sz>=1){
            
           a1=v[0].second;
           fa1=v[0].first; 
            
        }
        
        if(sz>=2){
            
            a2=v[1].second;
            fa2=v[1].first;
            
        }
        
        
        mp.clear();
        
        v.clear();
        
        for(int i=1;i<n;i+=2){
            mp[nums[i]]++;
        }
        
        for(auto itr:mp){
            v.push_back({itr.second,itr.first});
        }
        
        sort(v.rbegin(),v.rend());
        
        int b1=-1,b2=-1,fb1=0,fb2=0;
        
        sz=v.size();
        
        if(sz>=1){
            
           b1=v[0].second;
           fb1=v[0].first; 
            
        }
        
        if(sz>=2){
            
            b2=v[1].second;
            fb2=v[1].first;
            
        }
        
        cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<"\n";
        
        cout<<fa1<<" "<<fa2<<" "<<fb1<<" "<<fb2<<"\n";
        
        if(a1!=b1){
            
            ans=min(ans,req1-fa1+req2-fb1);
            
        }else{
            
            ans=min(ans,req1-fa1+req2-fb2);
            
        }
        
        if(a2!=b1){
            
            ans=min(ans,req1-fa2+req2-fb1);
            
        }
        
        return ans;
        
    }
};