//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for (int i = 0; i < V; i++)
                list.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
            }
            if (new Solution().isCyclic(V, list) == true)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/

class Solution {
    // Function to detect cycle in a directed graph.
    
    public boolean isCycle(int u,ArrayList<ArrayList<Integer>>adj,boolean vis[],boolean cvis[]){
        vis[u] = true;
        cvis[u] = true;
        for(int v:adj.get(u)){
            if(vis[v] == true){
                if(cvis[v] == true){
                    return true;
                }
            }
            else{
                boolean flag = isCycle(v,adj,vis,cvis);
                if(flag) return true;
            }
        }
        cvis[u] = false;
        return false;
    }
    
    public boolean isCyclic(int n, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[] = new boolean[n];
        boolean cvisited[] = new boolean[n];
        for(int i=0;i<n;i++){
            if(visited[i] == true) continue;
            if(isCycle(i,adj,visited,cvisited) == true){
                return true;
            }
        }
        return false;
    }
}