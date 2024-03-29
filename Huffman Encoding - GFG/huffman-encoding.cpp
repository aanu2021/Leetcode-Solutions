//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class MinheapNode{
  
  public:
  
  char data;
  int freq;
  MinheapNode*left;
  MinheapNode*right;
  
  MinheapNode(char data,int freq){
      this->data = data;
      this->freq = freq;
      this->left = NULL;
      this->right = NULL;
  }
    
};

struct comp{
  
  bool operator()(const MinheapNode*l,const MinheapNode*r){
      return l->freq > r->freq;
  }  
    
};

class Solution
{
	public:
	
	    vector<string>answer;
	    
	    void traverse(MinheapNode*& root,string &path){
	        if(!root) return;
	        if(root->data != '*'){
	            answer.push_back(path);
	        }
	        path += "0";
	        traverse(root->left,path);
	        path.pop_back();
	        path += "1";
	        traverse(root->right,path);
	        path.pop_back();
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<MinheapNode*,vector<MinheapNode*>,comp>pq;
		    for(int i=0;i<N;i++){
		        pq.push(new MinheapNode(S[i],f[i]));
		    }
		    while(pq.size() > 1){
		        auto left = pq.top();
		        pq.pop();
		        auto right = pq.top();
		        pq.pop();
		        auto tp = new MinheapNode('*',left->freq + right->freq);
		        tp->left = left;
		        tp->right = right;
		        pq.push(tp);
		    }
		    answer.clear();
		    string path = "";
		    MinheapNode * root = pq.top();
		    traverse(root,path);
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