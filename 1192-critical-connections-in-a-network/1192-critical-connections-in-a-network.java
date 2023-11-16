class Solution {
    
    int disc[];
    int low[];
    int parent[];
    static int timer;
    
    public void dfs(int u, ArrayList<Integer>graph[], List<List<Integer>>bridges){
        disc[u] = low[u] = timer++;
        for(int v : graph[u]){
            if(disc[v] == -1){
                parent[v] = u;
                dfs(v, graph, bridges);
                low[u] = Math.min(low[u], low[v]);
                if(low[v] > disc[u]){
                    List<Integer> list = new ArrayList<>();
                    list.add(u);
                    list.add(v);
                    bridges.add(list);
                }
            }
            else if(v != parent[u]){
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }
    
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> c) {
        
        ArrayList<Integer>graph[] = new ArrayList[n];
        disc = new int[n];
        low = new int[n];
        parent = new int[n];
        timer = 0;
        
        for(int i=0;i<n;i++){
            disc[i] = -1;
            low[i] = -1;
            parent[i] = -1;
        }
        
        for(int i=0;i<n;i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int i=0;i<c.size();i++){
            graph[c.get(i).get(0)].add(c.get(i).get(1));
            graph[c.get(i).get(1)].add(c.get(i).get(0));
        }
        
        List<List<Integer>>bridges = new ArrayList<>();        
        dfs(0, graph, bridges);
        return bridges;
        
    }
}