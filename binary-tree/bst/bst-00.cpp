/**************************Binary Tree Concepts****************************/
/*
Depth of Node x= length of path from root to Node x
Height of Node x = length of longest path from Node x to leafnode
Height of tree = Height of root = depth of deepest leafnode

Depth of root = 0
Height of leafnode = 0
Height of empty tree = -1
Height of tree with 1 Node = 0

A tree has several levels. Root Node is at level 0. Its children are in level 1.
Grandchildren are in level 2 and so on...

Binary Tree - At most 2 children
Proper/Strict Binary Tree - Either 0 or 2 children
Complete Binary Tree - All levels have to be filled except possibly the last level and
                       the nodes have to be as left as possible(it can be implemented by array as well)
Perfect Binary Tree - All levels are completely filled

Max possible nodes at each level i = 2^i
Max possible nodes of a binary tree of height h = 2^0 + 2^1 + ... + 2^h = 2^(h+1)-1
Min possible nodes of a binary tree of height h = h+1
Minimum height of tree having n Nodes = ceil(log(n+1))-1 = floor(log(n))
Maximum height of tree having n nodes = n-1

Balanced Binary Tree - difference between height of left and right subtree for
                       every node is not more than k(mostly 1)
Binary Search Tree - for each Node, the values in left subtree is less than or
                     equal and values in right subtree is greater. BST can be
                     balanced or unbalanced. 
*/

/*
We can use arrays to implement complete binary trees.
For Node at index i, left-child index is 2i+1 and right-child index is 2i+2.
*/




