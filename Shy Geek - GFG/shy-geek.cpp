//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/

typedef long long ll;

class Solution{
    
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        
        ll ans = 0LL;
        ll HIGH = n-1;
        ll low , high;
        
        while(true){
            
            low = 0 , high = HIGH;
            ll idx = -1LL;
            ll ele = -1LL;
            
            while(low <= high){
                
                ll mid = (low + high)/2;
                
                ll value = shop.get(mid);
                
                if(value <= k){
                    
                    idx = mid;
                    ele = value;
                    low = mid + 1;
                    
                }
                else{
                    
                    high = mid - 1;
                    
                }
                
            }
            
            if(idx == -1){
                break;
            }
            
            ans += (k/ele);
            k %= ele;
            
            if(k==0) break;
            
            HIGH = idx - 1LL;
            
        }
        
        return ans;
        
    }
    
    // n = 3
    // k = 5
    
    // 2 4 6
    
    // 1

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends