class Solution {
public:
    
    bool isMatch(string &s1,string &s2){
        
        int n=s1.length();
        
        int diff=0;
        
        for(int i=0;i<n;++i){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        
        return diff==1;
        
    }
    
    int ladderLength(string bW, string eW, vector<string>& wordList) {
        
        int n=wordList.size();
        
        queue<string>q;
        
        q.push(bW);
        
        unordered_set<string>S;
        
        unordered_set<string>dict;
        
        for(string str:wordList){
            dict.insert(str);
        }
        
        S.insert(bW);
        
        int lvl=0;
        
        string temp;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                if(curr==eW){
                    return lvl+1;
                }
                
                temp=curr;
                
                for(int i=0;i<curr.length();++i){
                    
                    for(char ch='a';ch<='z';ch++){
                        
                        temp[i]=ch;
                        
                        if(dict.find(temp)!=dict.end() && S.find(temp)==S.end()){
                            
                            q.push(temp);
                            S.insert(temp);
                            
                        }
                        
                        temp[i]=curr[i];
                        
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return 0;
        
    }
};