class Node{
    Node links[];
    boolean endWord;
    String fw;
    Node(){
        links = new Node[26];
        for(int i=0;i<26;i++){
            links[i] = null;
        }
        endWord = false;
    }
    boolean containsKey(char ch){
        return (links[ch-'a'] != null);
    }
    Node get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node node){
        links[ch-'a'] = node;
    }
}

class Solution {
    
    List<String>answer;
    Node root = new Node();
    
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    private void insertWords(String word){
        int n = word.length();
        Node node = root;
        for(int i=0;i<n;i++){
            if(node.containsKey(word.charAt(i)) == false){
                node.put(word.charAt(i), new Node());
            }
            node = node.get(word.charAt(i));
        }
        node.endWord = true;
        node.fw = word;
    }
    
    private void func(char[][] board,int i,int j,int m,int n,Node node){
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(board[i][j] == '*') return;
        if(node.containsKey(board[i][j]) == false) return;
        node = node.get(board[i][j]);
        if(node.endWord == true){
            node.endWord = false;
            answer.add(node.fw);
        }
        char temp = board[i][j];
        board[i][j] = '*';
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            func(board,ni,nj,m,n,node);
        }
        board[i][j] = temp;
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        answer = new ArrayList<>();
        int m = board.length;
        int n = board[0].length;
        for(String str : words){
            insertWords(str);
        }
        Node node = root;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                func(board,i,j,m,n,node);
            }
        }
        return answer;
    }
}