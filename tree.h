/*-----------------------------------------------------------------------------
Description: The only way to insert data in a tree is with the insert function.
So, the tree satisfies the Binary Search Tree Storage Rule. The function inTree
depends on this. < must be defined and give a well-behaved ordering to the type
T.

Author: Chibuikem Amaechi
Email: cramaechi@gmail.com
Date Created: 2016-10-17
Last Modified: 2016-12-12
------------------------------------------------------------------------------*/
#include <vector>
using std::vector;

#ifndef TREE_H
#define TREE_H
namespace TreeAmaechi
{
   template<class T>
   class SearchTree; //forward declaration

   template<class T>
   class TreeNode
   {
   public:
       TreeNode() : leftLink(NULL), rightLink(NULL), data(0) {}
       //Postcondition: Intializes a TreeNode object with a NULL pointer.

       TreeNode(T theData, TreeNode<T>* left, TreeNode<T>* right) : data(theData), leftLink(left), rightLink(right) {}
       //Postcondition: Intializes a TreeNode object with data, the left link and the right link.

       friend class SearchTree<T>; //Allows us to access the node member
                                   //variables by name in the tree definition.
   private:
      T data;
      TreeNode<T> *leftLink;
      TreeNode<T> *rightLink;
  };

  template<class T>
  class SearchTree
  {
  public:
      SearchTree() : root(NULL), treeHeight(0), treeSize(0) {} 
      //Postcondition: Initializes a SearchTree with an empty tree. 

      SearchTree(const SearchTree<T>& aSearchTree);
      //Postcondition: Initializes a SearchTree object that is a complete,
      //independent copy of 'aSearchTree';that is, a SearchTree object that
      //contains a separate but identical copy of the nodes in aSearchTree.

      bool remove(T item);
      //Postcondition: Returns true if item was found and removed; otherwise,
      //returns false.

      void insert(T item); //Adds item to the tree.
      
      void makeEmpty(); 
      //Postcondition: Removes all the nodes from the tree and returns
      //the memory used by the nodes for reuse.

      int height() const;
      //Postcondition: Returns the treeHeight of the tree 
      //(i.e., the maximum of the treeHeights of all the nodes.)
      
      int size() const;
      //Postcondition: Returns the number of nodes in the tree.

      bool inTree(T item) const;
      //Postcondition: Returns true if item is found in the tree, otherwise returns false.

      void preOrderTraversal() const;
      //Postcondition: Outputs data from the root node, left subtree, and right subtree, respectively.

      void inOrderTraversal() const;
      //Postcondition: Outputs data from the left subtree, root node, and right subtree, respectively.

      void postOrderTraversal() const;
      //Postcondition: Outputs data from the left subtree, right subtree, and root node, respectively.

      friend void process(T data);
      //Postcondition: Performs the underlying process operation of the tree of all three tree traversal techniques.

      SearchTree<T>& operator =(const SearchTree<T>& rightSide);
      //Postcondition: Returns a reference to the left SearchTree object (which
      //is the calling object) that is an identical copy (deep copy) of rightSide. 

      virtual ~SearchTree();
      //Postcondition: Destroys all the nodes in the tree and returns the memory used back to the heap.
  private:
      bool remove(unsigned int depth, T item, TreeNode<T>*& subTreeRoot);

      T findMaxData(TreeNode<T>*& subTreeRoot, unsigned int& depth);
      //Precondition: subTreeRoot is not NULL
      //Postcondition: Returns the largest node in the subtree.

      void insert(unsigned int depth, T item, TreeNode<T>*& subTreeRoot);

      bool inTree(T item, TreeNode<T>* subTreeRoot) const;

      void preOrderTraversal(TreeNode<T>* subTreeRoot) const;

      void inOrderTraversal(TreeNode<T>* subTreeRoot) const;

      void postOrderTraversal(TreeNode<T>* subTreeRoot) const;

      void copyTree(TreeNode<T>*& subTreeRoot1, const TreeNode<T>* subTreeRoot2);
      
      void updateTreeDepths(unsigned int depth, TreeNode<T>* subTreeRoot);

      void deleteSubTree(TreeNode<T>*& subTreeRoot);

      unsigned int treeSize; //Number of nodes in the tree.

      unsigned int treeHeight; //Number of links between the root node and the
                               //furthest leaf node.

      vector<unsigned int> depths; //Stores and maintains the # of nodes
                                   //for each depth level in the tree.

      TreeNode<T> *root; //Pointer to the root node of the tree.
  };

}//TreeAmaechi

#endif
