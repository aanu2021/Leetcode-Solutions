class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>Good;
        unordered_set<string>Visited;
        for(string &str : wordList){
            Good.insert(str);
        }
        if(Good.find(endWord) == Good.end()) return 0;
        queue<string>q;
        q.push(beginWord);
        Visited.insert(beginWord);
        int lvl = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto str = q.front(); q.pop();
                if(str == endWord) return lvl;
                for(int i=0;i<str.length();i++){
                    char prev = str[i];
                    for(char ch='a';ch<='z';ch++){
                        if(prev == ch) continue;
                        str[i] = ch;
                        if(Good.find(str) != Good.end()){
                            if(Visited.find(str) == Visited.end()){
                                Visited.insert(str);
                                q.push(str);
                            }
                        }
                    }
                    str[i] = prev;
                }
            }
            lvl++;
        }
        return 0;
    }
};