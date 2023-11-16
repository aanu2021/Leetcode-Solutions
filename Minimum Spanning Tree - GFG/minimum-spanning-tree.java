//{ Driver Code Starts


import java.util.*;
import java.io.*;
import java.lang.*;

public class Main{
	static BufferedReader br;
	static PrintWriter ot;
    public static void main(String args[]) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		ot = new PrintWriter(System.out);
		int t = Integer.parseInt(br.readLine().trim());
		while(t-- > 0){
			String s[] = br.readLine().trim().split(" ");
			int V = Integer.parseInt(s[0]);
			int E = Integer.parseInt(s[1]);
			int edges[][] = new int[E][3];
			for(int i = 0; i < E; i++){
				s = br.readLine().trim().split(" ");
				edges[i][0] = Integer.parseInt(s[0]);
				edges[i][1] = Integer.parseInt(s[1]);
				edges[i][2] = Integer.parseInt(s[2]);
			}
			ot.println(new Solution().spanningTree(V, E, edges));
		}
		ot.close();
	}
}
// } Driver Code Ends


// User function Template for Java

class Pair implements Comparable<Pair>{
    int node;
    int wt;
    Pair(int node, int wt){
        this.node = node;
        this.wt = wt;
    }
    public int compareTo(Pair p2){
        return this.wt - p2.wt;
    }
}

class Solution{
	static int spanningTree(int n, int m, int edges[][]){
	    int sumMST = 0;
	    ArrayList<Pair> graph[] = new ArrayList[n];
	    for(int i=0;i<n;i++){
	        graph[i] = new ArrayList<Pair>();
	    }
	    PriorityQueue<Pair> pq = new PriorityQueue<>();
	    boolean visited[] = new boolean[n];
	    pq.add(new Pair(0,0));
	    for(int i=0;i<m;i++){
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int wt = edges[i][2];
	        graph[u].add(new Pair(v,wt));
	        graph[v].add(new Pair(u,wt));
	    }
	    while(!pq.isEmpty()){
	        int node = pq.peek().node;
	        int wt = pq.peek().wt;
	        pq.remove();
	        if(visited[node] == true) continue;
	        visited[node] = true;
	        sumMST += wt;
	        for(Pair p : graph[node]){
	            int nbr = p.node;
	            int edgeWt = p.wt;
	            if(visited[nbr] == true) continue;
	            pq.add(new Pair(nbr,edgeWt));
	        }
	    }
	    return sumMST;
	}
}