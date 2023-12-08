class Solution {
    public String tree2str(TreeNode root) {
        if(root == null) return "";
        if(root.left == null && root.right == null) return Integer.toString(root.val);
        if(root.right == null){
            return Integer.toString(root.val) + "(" + tree2str(root.left) + ")" ;
        }
        else{
            return Integer.toString(root.val) + "(" + tree2str(root.left) + ")" + "(" + tree2str(root.right) + ")";
        }
    }
}