//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DSU{
   
   private:
   
   vector<int>Parent;
   vector<int>Size;
   
   public:
   
   DSU(int n){
       Parent.resize(n+1);
       Size.resize(n+1);
       for(int i=1;i<=n;i++){
           Parent[i] = i;
           Size[i] = 1;
       }
   }
   
   int find(int x){
       if(Parent[x]==x) return x;
       return Parent[x] = find(Parent[x]);
   }
   
   void Union(int x,int y){
       int lx = find(x);
       int ly = find(y);
       if(lx != ly){
           if(Size[lx] > Size[ly]){
               Size[lx] += Size[ly];
               Parent[ly] = lx;
           }
           else{
               Size[ly] += Size[lx];
               Parent[lx] = ly;
           }
       }
   }
   
   int getSize(int x){
       int lx = find(x);
       return Size[lx];
   }
};

class Solution{
public:

    vector<int>primeArr;
    bool prime[1000005];
    
    void sieve(){
        memset(prime,true,sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        for(int i=2;i*i<=1000000;i++){
            if(prime[i]){
                for(int j=i*i;j<=1000000;j+=i){
                    prime[j] = false;
                }
            }
        }
    }

    void precompute(){
        
        sieve();
        
        for(int i=1;i<=1000000;i++){
            if(prime[i]){
                primeArr.push_back(i);
            }
        }
        
        // for(int i=0;i<10;i++){
        //     cout<<primeArr[i]<<" ";
        // }cout<<"\n";
        
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){

        DSU obj(n);
        
        for(int i=1;i<=n;i++){
            for(int j : g[i]){
                obj.Union(i,j);
            }
        }
        
        int maxSize = 0;
        
        for(int i=1;i<=n;i++){
            if(obj.find(i) == i){
                maxSize = max(maxSize,obj.getSize(i));
            }
        }
        
        // cout<<maxSize<<"\n";
        
        if(maxSize == 1) return -1;
        
        return primeArr[maxSize-1];

    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends