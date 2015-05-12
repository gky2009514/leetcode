class Solution:
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
        res = []
        self._inOrder(root, res)
        return res

    def _inOrder(self, root, res):
        if not root:
            return
        self._inOrder(root.left, res)
        res.append(root.val)
        self._inOrder(root.right, res)