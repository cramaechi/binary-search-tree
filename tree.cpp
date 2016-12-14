/*-----------------------------------------------------------------------------
Description: This is the implementation for the template class SearchTree. The
interface is in the file tree.h.

Author: Chibuikem Amaechi
Email: cramaechi@gmail.com
Date Created: 2016-10-17
Last Modified: 2016-12-12
-------------------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "tree.h"
using namespace std;

namespace TreeAmaechi
{
   template<class T>
   SearchTree<T>::SearchTree(const SearchTree<T>& aSearchTree)
   {
      if (aSearchTree.root == NULL)
         root = NULL;
      else
      {
         treeSize = aSearchTree.treeSize;
         treeHeight = aSearchTree.treeHeight;
         copyTree(root, aSearchTree.root);
      }
   }
   
   template<class T>
   SearchTree<T>& SearchTree<T>::operator =(const SearchTree<T>& rightSide)
   {
      if (root == rightSide.root) //If the two trees are the same.
         return *this; 
      else  //Send the memory allocated to the left tree back to freestore.
         makeEmpty();
      
      if (rightSide.root == NULL)
      {
         root = NULL;
         return *this;
      }
      else
      {
         copyTree(root, rightSide.root);
         return *this;
      }
   } 
  
   template<class T>
   void SearchTree<T>::copyTree(TreeNode<T>*& subTreeRoot1, const TreeNode<T>* subTreeRoot2)
   {
      if (subTreeRoot2 != NULL)
      {
         subTreeRoot1 = new TreeNode<T>(subTreeRoot2->theData, NULL, NULL);
         copyTree(subTreeRoot1->leftLink, subTreeRoot2->leftLink);
         copyTree(subTreeRoot1->rightLink, subTreeRoot2->rightLink);
      }
   }
  
   template<class T>
   void SearchTree<T>::updateTreeDepths(unsigned int depth, TreeNode<T>* subTreeRoot)
   {
      if (subTreeRoot != NULL)
      {
         if (subTreeRoot->leftLink == NULL && subTreeRoot->rightLink == NULL)
         {
            --depths[depth];
            if (depths[depth] == 0)
               --treeHeight;

            return;
         }
         
         ++depth;
         updateTreeDepths(depth, subTreeRoot->leftLink);
         updateTreeDepths(depth, subTreeRoot->rightLink);
      }
   }
      
   template<class T>
   bool SearchTree<T>::remove(unsigned int depth, T item, TreeNode<T>*& subTreeRoot)
   {
      if (subTreeRoot != NULL)
      {
         TreeNode<T> *discard = subTreeRoot;
         if (subTreeRoot->data == item)
         {
            if (subTreeRoot->leftLink != NULL && subTreeRoot->rightLink == NULL)
            {
               subTreeRoot = subTreeRoot->leftLink;
               updateTreeDepths(++depth, subTreeRoot); //Decrements one of the elements in the member array variable 'depths'.
               delete discard;

               return true;
            }
            else if (subTreeRoot->leftLink == NULL && subTreeRoot->rightLink != NULL)
            {
               subTreeRoot = subTreeRoot->rightLink;
               updateTreeDepths(++depth, subTreeRoot); 
               delete discard;
               
               return true;
            }
            else if (subTreeRoot->leftLink == NULL && subTreeRoot->rightLink == NULL)
            {
               updateTreeDepths(depth, subTreeRoot);
               subTreeRoot = NULL;
               delete discard;

               return true;               
            }
            else
            {
               subTreeRoot->data = findMaxData(subTreeRoot->leftLink, ++depth);
               return true;               
            }
         }
         else if (item < subTreeRoot->data) 
            return remove(++depth, item, subTreeRoot->leftLink);
         else //item >= link->data 
            return remove(++depth, item, subTreeRoot->rightLink); 
      }
      return false;
   }
     
   template<class T>
   T SearchTree<T>::findMaxData(TreeNode<T>*& subTreeRoot, unsigned int& depth)
   {
      if (subTreeRoot->rightLink == NULL)
      {
         T data = subTreeRoot->data;
         remove(depth, data, subTreeRoot); 
         return data;
      }
      else
         return findMaxData(subTreeRoot->rightLink, ++depth);
   }
   
   template<class T>
   bool SearchTree<T>::remove(T item)
   {
      --treeSize;
      return remove(0, item, root);
   }

   template<class T>
   void SearchTree<T>::insert(unsigned int depth, T item, TreeNode<T>*& subTreeRoot)
   {
      if (subTreeRoot == NULL) 
      {
         subTreeRoot = new TreeNode<T>(item, NULL, NULL); 
         if (depth > treeHeight)
         {
            depths.push_back(1);
            ++treeHeight;
         }
         else if (depth <= treeHeight && depth != 0)
            ++depths[depth];
         else
            depths.push_back(1);
      }
      else if (item < subTreeRoot->data)
         insert(++depth, item, subTreeRoot->leftLink);
      else //item >= link->data
         insert(++depth, item, subTreeRoot->rightLink);
   }
   
   template<class T>
   void SearchTree<T>::insert(T item)
   {
      ++treeSize;
      insert(0, item, root);
   }
   
   template<class T>
   int SearchTree<T>::size() const
   {
      return treeSize;
   }

   template<class T>
   int SearchTree<T>::height() const
   {
      return treeHeight; 
   }
   
   template<class T>
   void SearchTree<T>::deleteSubTree(TreeNode<T>*& subTreeRoot)
   {
      if (subTreeRoot != NULL)
      {
         deleteSubTree(subTreeRoot->leftLink);
         deleteSubTree(subTreeRoot->rightLink);

         /*Before the following line of code, subTreeRoot now points to a one node tree.*/
         delete subTreeRoot;
         subTreeRoot = NULL;
      }
   }
   
   template<class T>
   SearchTree<T>::~SearchTree()
   {
      deleteSubTree(root);
   }
   
   template<class T>
   bool SearchTree<T>::inTree(T item, TreeNode<T>* subTreeRoot) const
   {
      if (subTreeRoot == NULL)
         return false;
      else if (subTreeRoot->data == item)
         return true;
      else if(item < subTreeRoot->data)
         return inTree(item, subTreeRoot->leftLink);
      else //item >= link->data
         return inTree(item, subTreeRoot->rightLink);
   }
   
   template<class T>
   bool SearchTree<T>::inTree(T item) const
   {
      return inTree(item, root);
   }

   template<class T>
   void process(T data) //This function serves as a stub.
   {
      cout<<data<<" ";
   }

   template<class T>
   void SearchTree<T>::preOrderTraversal(TreeNode<T>* subTreeRoot) const
   {
      if (subTreeRoot != NULL)
      {
         process(subTreeRoot->data);
         preOrderTraversal(subTreeRoot->leftLink);
         preOrderTraversal(subTreeRoot->rightLink);
      }
   }

   template<class T>
   void SearchTree<T>::preOrderTraversal() const
   {
      preOrderTraversal(root);
   }
   
   template<class T>
   void SearchTree<T>::inOrderTraversal(TreeNode<T>* subTreeRoot) const
   {
      if (subTreeRoot != NULL)
      {
         inOrderTraversal(subTreeRoot->leftLink);
         process(subTreeRoot->data);
         inOrderTraversal(subTreeRoot->rightLink);
      }
   }
   
   template<class T>
   void SearchTree<T>::inOrderTraversal() const
   {
      inOrderTraversal(root);
   }
   
   template<class T>
   void SearchTree<T>::postOrderTraversal(TreeNode<T>* subTreeRoot) const
   {
      if (subTreeRoot != NULL)
      {
         postOrderTraversal(subTreeRoot->leftLink);
         postOrderTraversal(subTreeRoot->rightLink);
         process(subTreeRoot->data);
      }
   }

   template<class T>
   void SearchTree<T>::postOrderTraversal() const
   {
      postOrderTraversal(root);
   }
   
}
