class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        res = []
        self._preOrder(root, res)
        return res

    def _preOrder(self, root, res):
        if not root:
            return
        res.append(root.val)
        self._preOrder(root.left, res)
        self._preOrder(root.right, res)