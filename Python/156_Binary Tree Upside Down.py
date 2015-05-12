class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    res = None
    def upsideDownBinaryTree(self, root):
        if root is None:
            return root
        self._upsideDown(root, None)
        return self.res

    def _upsideDown(self, root, parent):
        if root is None:
            return
        self._upsideDown(root.left, root)
        if self.res is None:
            self.res = root
        if parent is not None:
            root.left = parent.right
            root.right = parent
        else:
            root.left = root.right = None