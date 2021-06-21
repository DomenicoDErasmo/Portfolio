/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
    private int getMax(List<Integer> list)
    {
        int max = list.get(0);
        for (int i = 1; i < list.size(); i++)
        {
            if (list.get(i) > max)
            {
                max = list.get(i);
            }
        }
        return max;
    }
    
    private int maxDepthHelper(Node root, int depth)
    {
        List<Integer> depths = new ArrayList<Integer>();
        if (root == null)
        {
            return depth - 1;
        }
        else if (root.children.isEmpty())
        {
            return depth;
        }
        else
        {
            for (int i = 0; i < root.children.size(); i++)
            {
                depths.add(maxDepthHelper(root.children.get(i), depth + 1));
            }
            return getMax(depths);
        }
    }
    
    public int maxDepth(Node root) 
    {
        return maxDepthHelper(root, 1);    
    }
}