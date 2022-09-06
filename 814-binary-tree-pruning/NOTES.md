Here we recursively traverse the nodes in binary tree and check:
​
* If The current sub-tree is contains 1(if and only if root.val == 1 or leftSubTree contains 1 or rightSubTree contains 1) then return root.
* If The above condition doesn't satisfy then return NULL.
* Finally Set the root->left == NULL if it's leftSubTree doesn't contain 1 otherwise keep the root->left as the original node.
* Do the same for the root->right as well with the same condtions.