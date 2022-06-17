class Solution {
public:
    
    bool isPossible(vector<int>&houses,vector<int>&heaters,int radius){
        
        int m=houses.size();
        int n=heaters.size();
        
        int i=0,j=0;
        
        while(i<m){
            
            if(j==n){
                return false;
            }
            
            int l=heaters[j]-radius;
            int r=heaters[j]+radius;
            
            if(houses[i]<l || houses[i]>r){
                j++;
            }else{
                i++;
            }
            
        }
        
        return true;
        
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int low=0,high=1e9;
        
        int ans=-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(isPossible(houses,heaters,mid)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        
        return ans;
        
    }
};