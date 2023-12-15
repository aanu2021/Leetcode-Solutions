class Solution {
    public String destCity(List<List<String>> paths) {
        HashMap<String,Integer>outdegree = new HashMap<>();
        for(int i=0;i<paths.size();i++){
            String source = paths.get(i).get(0);
            if(outdegree.containsKey(source)){
                outdegree.put(source, outdegree.get(source) + 1);
            }
            else{
                outdegree.put(source, 1);
            }
        }
        for(int i=0;i<paths.size();i++){
            String destination = paths.get(i).get(1);
            if(outdegree.containsKey(destination)) continue;
            else return destination;
        }
        return "";
    }
}