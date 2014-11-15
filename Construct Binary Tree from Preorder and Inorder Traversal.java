/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0)
            return null;
        return trueStuff(preorder,0,preorder.length - 1,inorder,0,inorder.length - 1);
    }
    private TreeNode trueStuff(int[] pre,int startp,int finp,int[] in,int starti,int fini)
    {
        if (startp == finp)
            return new TreeNode(pre[startp]);
        if (startp > finp)
            return null;
        TreeNode tmp = new TreeNode(pre[startp]);
        int pos = findIndex(in,starti,fini,pre[startp]);
        if (pos == -1)
            return null;
        tmp.left = trueStuff(pre,startp + 1,startp + pos - starti,in,starti,pos - 1);
        tmp.right = trueStuff(pre,startp + pos - starti + 1,finp,in,pos + 1,fini); 
        return tmp;
    }
    private int findIndex(int[] in,int start,int fin,int target)
    {
        for (int i = start;i <= fin;i++)
            if (in[i] == target)
                return i;
        return -1;
    }
}