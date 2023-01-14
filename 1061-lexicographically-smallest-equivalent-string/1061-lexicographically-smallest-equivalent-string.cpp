class Solution {
public:
    
    int Parent[26];
    int Rank[26];
    
    int find(int x){
        if(Parent[x] == x) return x;
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
                if(Rank[lx] == Rank[ly]) Rank[lx]++;
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        for(int i=0;i<26;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
        
        // Grouping of all characters to access their leader 
        
        for(int i=0;i<n;i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        
        vector<char>minElement(26);
        
        // First initialize all the characters with their current value , e.g 'a' -> 'a' , 'c' -> 'c' and so on.
        
        for(int i=0;i<26;i++){
            minElement[i] = (char)(i+'a');
        }
        
        // first figure out the current element belongs to which group and then mark its leader's value with the minimum value among all the characters of the same group-members.
        
        for(int i=0;i<26;i++){
            int par = find(i);
            minElement[par] = min(minElement[par],(char)(i+'a'));
        }
        
        // Now move on to the baseStr , and for each character , and figure out the group leader of the group , in which the current character belongs to.
        
        // Then just put the minElement[group_leader] for each and every character , as they are already precomputed by us earlier.
        
        for(int i=0;i<baseStr.length();i++){
            int par = find(baseStr[i]-'a');
            baseStr[i] = minElement[par];
        }
        
        return baseStr;
        
    }
};