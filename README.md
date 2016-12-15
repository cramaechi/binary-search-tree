# Binary Search Tree
My implementation of a binary tree that satisfies the Binary Search Tree Storage Rule.

#### Binary Search Tree Storage Rule
1. All the values in the left subtree are less than the value in the root node.
2. All the values in the right subtree are greater than or equal to the value in the rood node.
3. This rule applies recursively to each of the two subtrees.

If you don't know what a binary tree is or what it is used for, then [read this first] (https://en.wikipedia.org/wiki/Binary_tree).

## Setup
1. Download and install [Git] (https://git-scm.com/downloads), if you don't already have it.

2. Open your terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/binary-search-tree.git
   ```
    or [download as ZIP]
    (https://github.com/cramaechi/binary-search-tree/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd binary-search-tree
   ```

4. Compile:

   ```
   $ make
   ```

5. Run:

   ```
   $ ./tree_demo
   ```

## Testing
```
Enter up to 15 nonnegative integers, and press Return.
5 8 2 1 6 13 3 4 0 9

The size of the tree is: 10
The height of the tree is: 3

The preorder traversal of the tree is: 5 2 1 0 3 4 8 6 13 9
The in-order traversal of the tree is: 0 1 2 3 4 5 6 8 9 13 
The postorder traversal of the tree is: 0 1 4 3 2 6 9 13 8 5

Would you like to remove an item from the tree? (y/n): y

Select item: 4

The size of the tree is: 9
The height of the tree is: 3

The preorder traversal of the tree is: 5 2 1 0 3 8 6 13 9 
The in-order traversal of the tree is: 0 1 2 3 5 6 8 9 13 
The postorder traversal of the tree is: 0 1 3 2 6 9 13 8 5 

Would you like to remove an item from the tree? (y/n): n

Okay, goodbye!
```
