/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode deleteFromBST(TreeNode root){
        if(root.left == null) return root.right;
        if(root.right == null) return root.left;
        TreeNode leftNode = root.left;
        TreeNode rightNode = root.right;
        while(leftNode != null && leftNode.right != null){
            leftNode = leftNode.right;
        }
        leftNode.right = rightNode;
        root.right = null;
        return root.left;
    }
    
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return root;
        if(root.val == key){
            root = deleteFromBST(root);
            return root;
        }
        TreeNode node = root;
        while(node != null){
            if(node.val > key){
                if(node.left != null && node.left.val == key){
                    node.left = deleteFromBST(node.left);
                    return root;
                }
                else{
                    node = node.left;
                }
            }
            else{
                if(node.right != null && node.right.val == key){
                    node.right = deleteFromBST(node.right);
                    return root;
                }
                else{
                    node = node.right;
                }
            }
        }
        return root;
    }
}