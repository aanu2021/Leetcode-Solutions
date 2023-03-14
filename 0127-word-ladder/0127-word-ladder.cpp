class Solution {
public:
    
    /*
    
    Time Complexity  : O(wordListLen * beginWordLen * 26)
    Space Complexity : O(wordListLen * beginWordLen * 26)
    
    */
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>dict;
        unordered_set<string>vis;
        
        for(string &str : wordList){
            dict.insert(str);
        }
        if(dict.find(endWord) == dict.end()) return 0;
        
        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        
        int lvl = 0;
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                
                string word = q.front();
                q.pop();
                if(word == endWord) return lvl + 1;
                
                for(int i=0;i<word.length();i++){
                    char pre = word[i];
                    for(char ch='a';ch<='z';ch++){
                        if(ch==pre) continue;
                        word[i] = ch;
                        if(dict.find(word) != dict.end()){
                            if(vis.find(word) == vis.end()){
                                vis.insert(word);
                                q.push(word);
                            }
                        }
                        word[i] = pre;
                    }
                }
                
            }
            
            lvl++;
        }
        
        return 0;
        
    }
};