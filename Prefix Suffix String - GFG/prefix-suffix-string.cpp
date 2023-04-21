//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct Node{
  
  Node*links[26];
  bool endWord;
  
  Node(){
      for(int i=0;i<26;i++){
          links[i] = NULL;
      }
      endWord = false;
  }
  
  bool containsKey(char ch){
      return (links[ch-'a'] != NULL);
  }
  void put(char ch,Node*node){
      links[ch-'a'] = node;
  }
  Node*get(char ch){
      return links[ch-'a'];
  }
  void setEnd(){
      endWord = true;
  }
  bool getEnd(){
      return endWord;
  }
    
};

class Trie{
  
  public:
  
  Node*root;
  
  Trie(){
      root = new Node();
  }
  
  void insertWord(string &word){
      Node*node = root;
      for(int i=0;i<word.length();i++){
          if(!node->containsKey(word[i])){
              node->put(word[i],new Node());
          }
          node = node->get(word[i]);
      }
      node->setEnd();
  }
  
  bool isMatch(string &word){
      Node * node = root;
      for(int i=0;i<word.length();i++){
          if(!node->containsKey(word[i])) return false;
          node = node->get(word[i]);
      }
      return true;
  }
    
};

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){

       int m = s1.size();
       int n = s2.size();
       
       Trie obj1;
       for(int i=0;i<m;++i){
           obj1.insertWord(s1[i]);
       }
       
       for(int i=0;i<m;i++){
           reverse(s1[i].begin(),s1[i].end());
       }
       Trie obj2;
       for(int i=0;i<m;i++){
           obj2.insertWord(s1[i]);
       }
       
       int ans = 0;
       for(int i=0;i<n;i++){
           string str = s2[i];
           if(obj1.isMatch(str)){
               ans++;
           }
           else{
               reverse(str.begin(),str.end());
               if(obj2.isMatch(str)){
                   ans++;
               }
           }
       }
       
       return ans;

    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends