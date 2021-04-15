#include <iostream>
#include "ScatterFunction.h"
#include "HashTable.h"
#include "HashTable.cpp"
#include "fdModule.cpp"
#include "fdModule2.cpp"
using namespace std;
int main()
{
     int size; //for taking size from user
     ScatterFunction<int>* ptr; //for taking type of Hashing Module from user
     cout << "Enter the size of HashTable: ";
     cin >> size;
     int x;
     while (true) //loops until user selects a right choice from the menu..
     {
          cout << "Which Hashing Module would you like to select?(Enter 1 or 2): ";
          cin >> x;
          if (x == 1)
          {
               ptr = new fdModule<int>(size); //setting Hashing Module to fdModule if user selected one
               break;
          }
          else if(x==2)
          {
               ptr = new fdModule2<int>(size); //setting Hashing Module to fdModule 2 if user selected 2
               break;
          }
          cout << "Incorrect!!!\n";
     }

     
     HashTable<int> ht(size,ptr); //hashtable of size selected by user and pointer to the Scatter Function(Hashing Module) selected by the user
     while (true) //loop forever in the menu
     {
          system("CLS"); //clear screen
          int choice;
          cout << "1. Insert an element\n2. Search for an element\nAnything else to Quit.\nEnter from above choices: ";
          cin >> choice;
          if (choice == 1)
          {
               cout << "Enter a value to be inserted: ";
               cin >> choice;
               if (ht.Insert(choice)) //if insertion is successfull
                    cout << "Insertion Successful" << endl;
               else
                    cout << "Insertion Failed Because element exists!!" << endl;
          }
          else if (choice == 2)
          {
               cout << "Enter a value to be searched: ";
               cin >> choice;
               if (ht.Search(choice)) //if element is found in the hashtable
                    cout << "Element exists!!"  << endl;
               else
                    cout << "Element does not exist!!" << endl;
          }
          else
          {
               break;
          }
          system("PAUSE");
     }
     return 0;
}