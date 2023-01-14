class Solution {
public:
    
    vector<int>Parent;
    vector<int>Rank;
    
    int find(int x){
        if(Parent[x]==x) return x;
        return Parent[x] = find(Parent[x]);
    }
    
    void Union(int x,int y){
        int lx = find(x);
        int ly = find(y);
        if(lx != ly){
            if(Rank[lx] < Rank[ly]){
                Parent[lx] = ly;
            }
            else{
                Parent[ly] = lx;
                if(Rank[lx] == Rank[ly]){
                    Rank[lx]++;
                }
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        Parent.resize(26);
        Rank.resize(26);
        for(int i=0;i<26;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
        for(int i=0;i<n;i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        vector<char>actualChar(26);
        for(int i=0;i<26;i++){
            actualChar[i] = (char)(i+'a');
        }
        for(int i=0;i<26;i++){
            int p = find(i);
            actualChar[p] = min(actualChar[p],(char)(i+'a'));
        }
        for(int i=0;i<baseStr.length();i++){
            int currIdx = baseStr[i] - 'a';
            int par = find(currIdx);
            baseStr[i] = actualChar[par];
        }
        return baseStr;
    }
};

// p -> m
// a -> o
// r -> r
// k -> r
// e -> i
// r -> s