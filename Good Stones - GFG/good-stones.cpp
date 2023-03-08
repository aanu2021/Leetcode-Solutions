//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int goodStones(int n,vector<int> &arr){
       int ans = 0;
       vector<int>visited(n,0);
       for(int i=0;i<n;i++){
           if(visited[i] != 0) continue;
           bool good = false;
           int j = i;
           int comp = 0;
           while(true){
               visited[j] = 1;
               comp++;
               j += arr[j];
               if(j < 0 || j >= n || visited[j] == 3){
                   good = true;
                   break;
               }
               if(visited[j] == 1 || visited[j] == 2){
                   good = false;
                   break;
               }
           }
           if(good){
               ans += comp;
               j = i;
               while(comp > 0){
                   visited[j] = 3;
                   j += arr[j];
                   comp--;
               }
           }
           else{
               j = i;
               while(comp > 0){
                   visited[j] = 2;
                   j += arr[j];
                   comp--;
               }
           }
       }
       return ans;
    }  
};


 /*
 
 unvisited stones -> 0
 visited stones -> 1
 bad stones -> 2
 good stones -> 3

 2  3 -1  2 -2  4  1
 0  1  2  3  4  5  6
        
        j = 0 -> 2 -> 1 -> 4 -> 2
        j = 3 -> 5 -> 9
        j = 6 -> 7
        
*/


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends