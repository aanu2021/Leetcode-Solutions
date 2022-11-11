class Solution {
public:
    
    /*
    
    T.C : O(N*N)
    S.C : O(1)
    
    */
    
    int subarrayGCD2(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int g = nums[i];
            for(int j=i;j<n;j++){
                g = __gcd(g,nums[j]);
                if(g<k){
                    break;
                }
                if(g==k) ans++;
            }
        }
        return ans;
    }
    
    /*
    
    T.C : O(N*log(max(arr)))
    S.C : O(log(max(arr)))
    
    */
    
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>gcd_prev;
        if(nums[0]==k) ans++;
        gcd_prev[nums[0]]++;
        for(int i=1;i<n;i++){
            unordered_map<int,int>gcd_new;
            int curr = nums[i];
            gcd_prev[nums[i]]++;
            for(auto &itr:gcd_prev){
                int key = itr.first;
                int freq = itr.second;
                int currgcd = __gcd(key,curr);
                if(currgcd==k) ans+=freq;
                gcd_new[currgcd]+=freq;
            }
            gcd_prev = gcd_new;
        }
        return ans;
    }
    
};


      
      