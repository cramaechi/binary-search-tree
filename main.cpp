//Driver program for the Tree template class.
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "tree.h" //Not required. Simply for documentation purposes.
#include "tree.cpp" //It is standard to include the implementation file for a
                    //template class inside any program that uses it.
using std::cin;
using std::cout;
using std::endl;
using TreeAmaechi::SearchTree;

int main()
{
   SearchTree<int> t1;

   char listOfNumbers[30];
   cout<<"\nEnter up to 15 nonnegative integers, and press Return.\n";
   cin.getline(listOfNumbers, 30);

   char *i = strtok(listOfNumbers, " ");
   while (i != NULL)
   {
      t1.insert(atoi(i));
      i = strtok(NULL, " ");
   }

   char ans;
   do
   {
      cout<<"\nThe size of the tree is: "<<t1.size()<<endl;
      cout<<"The height of the tree is: "<<t1.height()<<endl;

      cout<<"\nThe preorder traversal of the tree is: ";
      t1.preOrderTraversal();
      cout<<"\nThe in-order traversal of the tree is: ";
      t1.inOrderTraversal();
      cout<<"\nThe postorder traversal of the tree is: ";
      t1.postOrderTraversal();

      cout<<"\n\nWould you like to remove an item from the tree? (y/n): ";
      cin>>ans;

      if (ans == 'y' || ans == 'Y')
      {
         bool success;
         do
         {
            cout<<"\nSelect item: ";
            int discard;
            cin>>discard;

            success = t1.remove(discard);
         }while(!success);
      }
      else
      {
         cout<<"\nOkay, goodbye!\n";
         break;
      }

   }while(ans == 'y' || ans == 'Y');

   return 0;
}
