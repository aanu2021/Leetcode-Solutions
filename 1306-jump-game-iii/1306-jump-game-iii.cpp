class Solution {
public:
    
    map<int,bool>mp;
    
    bool func(vector<int>&arr,int i){
        
        if(i<0 || i>=arr.size()){
            return false;
        }
        
        if(arr[i]==0){
            return true;
        }
        
        if(mp[i]==true){
            return false;
        }
        
        mp[i]=true;
        
        return func(arr,i-arr[i]) || func(arr,i+arr[i]);
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        
        return func(arr,start);
        
    }
};