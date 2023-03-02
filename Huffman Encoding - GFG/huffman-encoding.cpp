//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class MinheapNode{
  
  public:
  
  char data;
  int freq;
  MinheapNode * left;
  MinheapNode * right;
  
  MinheapNode(char data,int freq){
      this->data = data;
      this->freq = freq;
      this->left = NULL;
      this->right = NULL;
  }
    
};

struct comp{
  
  bool operator()(MinheapNode*l,MinheapNode*r){
      return l->freq > r->freq;
  }
    
};

class Solution
{
	public:
	
	    vector<string>answer;
	
	    void traverse(MinheapNode*root,string path){
	        if(!root) return;
	        if(root->data != '$'){
	           answer.push_back(path);
	        }
	        traverse(root->left,path+"0");
	        traverse(root->right,path+"1");
	    }
	
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    priority_queue<MinheapNode*,vector<MinheapNode*>,comp>pq;
		    for(int i=0;i<n;i++){
		        pq.push(new MinheapNode(s[i],f[i]));
		    }
		    while(pq.size() != 1){
		        auto left = pq.top(); pq.pop();
		        auto right = pq.top(); pq.pop();
		        auto tp = new MinheapNode('$',left->freq+right->freq);
		        tp->left = left;
		        tp->right = right;
		        pq.push(tp);
		    }
		    answer.clear();
		    traverse(pq.top(),"");
		    // cout<<mapping.size()<<"\n";
		    return answer;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends