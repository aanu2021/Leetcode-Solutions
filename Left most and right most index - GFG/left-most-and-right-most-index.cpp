//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
       pair<long,long>ans = {-1,-1};
       int n = v.size();
       int l = 0,r = n-1;
       while(l<=r){
           int mid = (l + r) / 2;
           if(v[mid]==x){
               ans.first = mid;
               r = mid - 1;
           }
           else if(v[mid] > x){
               r = mid - 1;
           }
           else{
               l = mid + 1;
           }
       }
       l = 0,r = n-1;
       while(l<=r){
           int mid = (l + r)/2;
           if(v[mid]==x){
               ans.second = mid;
               l = mid + 1;
           }
           else if(v[mid] > x){
               r = mid - 1;
           }
           else{
               l = mid + 1;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends