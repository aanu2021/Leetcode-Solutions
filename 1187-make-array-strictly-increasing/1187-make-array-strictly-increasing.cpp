class Solution {
public:
    
    int MAX = 2005;
    
    int dp[2002][2002][2];
    
    int func(vector<int>&arr1,vector<int>&arr2,int i,int j,bool prev){
        
        if(i == arr1.size()) return 0;
        if(j == arr2.size()) return MAX;
        
        if(dp[i][j][prev] != -1) return dp[i][j][prev];
        
        int previous_val = -1;
        
        if(i > 0){
            if(prev)  previous_val = arr1[i-1];
            else      previous_val = arr2[j];
        }
        
        int idx = upper_bound(arr2.begin(),arr2.end(),previous_val) - arr2.begin();
        
        int ops = MAX;
        
        if(idx < arr2.size()){
            ops = 1 + func(arr1,arr2,i+1,idx,false);
        }
        
        if(arr1[i] > previous_val){
            ops = min(ops, func(arr1,arr2,i+1,j,true));
        }
        
        return dp[i][j][prev] = ops;
        
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();
        int m = arr2.size();
        
        sort(arr2.begin(),arr2.end());
        memset(dp,-1,sizeof(dp));
        
        int ans = func(arr1,arr2,0,0,true);
        
        return ans >= MAX ? -1 : ans;
        
    }
};

/*

1 5 3 6 7
1 2 3 4
    
1. arr[i] remain as it is
2. arr[i] swap with appropriate arr[j]

when we are swapping, it is optimal to place the smallest element, which is just greater than previous value.
    
dp[i][j][prev]

at index i -> arr1
prefix of length (j+1) -> arr2
prev -> previous value, true  -> arr1[i-1]
                        false -> arr2[j]
                        
           */             