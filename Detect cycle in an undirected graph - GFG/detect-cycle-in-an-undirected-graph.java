//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, adj);
            if (ans)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


class Pair{
    int node;
    int parent;
    Pair(int node, int parent){
        this.node = node;
        this.parent = parent;
    }
}

class Solution {
    // Function to detect cycle in an undirected graph.
    
    public boolean isCyclic(int u,int p,ArrayList<ArrayList<Integer>> adj, boolean visited[]){
        visited[u] = true;
        for(int v : adj.get(u)){
            if(v == p) continue;
            if(visited[v] == true) return true;
            boolean flag = isCyclic(v,u,adj,visited);
            if(flag) return true;
        }
        return false;
    }
    
    public boolean isCyclic2(int n, ArrayList<ArrayList<Integer>> adj){
        boolean visited[] = new boolean[n];
        for(int i=0;i<n;i++){
            if(visited[i] == true) continue;
            Queue<Pair>q = new LinkedList<>();
            q.add(new Pair(i,-1));
            visited[i] = true;
            while(!q.isEmpty()){
                int node = q.peek().node;
                int parent = q.peek().parent;
                q.remove();
                for(int nbr : adj.get(node)){
                    if(nbr == parent) continue;
                    if(visited[nbr] == true) return true;
                    visited[nbr] = true;
                    q.add(new Pair(nbr,node));
                }
            }
        }
        return false;
    }
    
    public boolean isCycle(int n, ArrayList<ArrayList<Integer>> adj) {
        return isCyclic2(n,adj);
        // boolean visited[] = new boolean[n];
        // for(int i=0;i<n;i++){
        //     if(visited[i] == true) continue;
        //     if(isCyclic(i,-1,adj,visited) == true) return true;
        // }
        // return false;
    }
}