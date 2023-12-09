class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        while(root != null){
            if(root.left == null){
                answer.add(root.val);
                root = root.right;
            }
            else{
                TreeNode leftNode = root.left;
                while(leftNode != null && leftNode.right != null && leftNode.right != root){
                    leftNode = leftNode.right;
                }
                if(leftNode.right == null){
                    leftNode.right = root;
                    root = root.left;
                }
                else{
                    answer.add(root.val);
                    leftNode.right = null;
                    root = root.right;
                }
            }
        }
        return answer;
    }
}