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
class Solution 
{
    public boolean IsEven(TreeNode root)
    {
        return root.val % 2 == 0;
    }
    
    public boolean HasGrandChildren(TreeNode root)
    {
        if (root.left != null)
        {
            if (root.left.left != null || root.left.right != null)
            {
                return true;
            }
        }
        if (root.right != null)
        {
            if (root.right.left != null || root.right.right != null)
            {
                return true;
            }
        }
        return false;
    }
    
    public int SumOfGrandChildren(TreeNode root)
    {
        int sum = 0;
        if (root.left != null)
        {
            if (root.left.left != null)
            {
                sum += root.left.left.val;
            }
            if (root.left.right != null)
            {
                sum += root.left.right.val;
            }
        }
        if (root.right != null)
        {
             if (root.right.left != null)
            {
                sum += root.right.left.val;
            }
            if (root.right.right != null)
            {
                sum += root.right.right.val;
            }
        }
        return sum;
    }
    
    public int sumEvenGrandparent(TreeNode root) 
    {
        // idea: do BFS, if node is even, try and find grandchildren and return the sum of these grandchildren
        int sum = 0;
        LinkedList<TreeNode> list = new LinkedList<TreeNode>();
        list.add(root);
        while(!list.isEmpty())
        {
            TreeNode temp = list.peek();
            if(IsEven(temp) && HasGrandChildren(temp))
            {
                System.out.println(temp.val + " has grandchildren");
                sum += SumOfGrandChildren(temp);
            }
            if (temp.left != null)
            {
                list.add(temp.left);
            }
            if (temp.right != null)
            {
                list.add(temp.right);
            }
           
            list.remove();
        }
        return sum;
    }
}