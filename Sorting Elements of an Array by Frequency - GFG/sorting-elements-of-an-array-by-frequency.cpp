//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        vector<int>answer;
        vector<vector<int>>vec(n+1);
        for(auto &itr : freq){
            vec[itr.second].push_back(itr.first);
        }
        for(int i=n;i>=1;i--){
            if(vec[i].size() == 0) continue;
            sort(vec[i].begin(),vec[i].end());
            int occ = i;
            for(int &ele : vec[i]){
                occ = i;
                while(occ > 0){
                    answer.push_back(ele);
                    occ--;
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends