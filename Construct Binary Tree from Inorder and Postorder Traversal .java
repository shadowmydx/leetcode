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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (postorder.length == 0)
            return null;
        return trueStuff(postorder,0,postorder.length - 1,inorder,0,inorder.length - 1);
    }
    private TreeNode trueStuff(int[] pre,int startp,int finp,int[] in,int starti,int fini)
    {
        if (startp == finp)
            return new TreeNode(pre[finp]);
        if (startp > finp)
            return null;
        TreeNode tmp = new TreeNode(pre[finp]);
        int pos = findIndex(in,starti,fini,pre[finp]);
        if (pos == -1)
            return null;
        tmp.left = trueStuff(pre,startp,startp + pos - starti - 1,in,starti,pos - 1);
        tmp.right = trueStuff(pre,startp + pos - starti,finp - 1,in,pos + 1,fini); 
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