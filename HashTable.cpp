#pragma once
#include "HashTable.h"
#include "ScatterFunction.h"
template <class Key>
HashTable<Key>::HashTable(int size, ScatterFunction<Key>* f)
{
     nData = size; //setting the class object's nData to the size passed to constructor
     vData = new Key[size]; //Allocating Dynamic memory
     fd = f; // Setting pointer to Scatter function to the value passed to the constructor
}
template <class Key>
bool HashTable<Key>::Search(Key& X)const
{
     unsigned index = fd->hash(X); //getting Hash of X from Pointer to Scatter function
     if (vData[index] == X) //check if the element exists on the index of Hash of X
     {
          return true; //return true if a key is found
     }
     else
     {
          return false; //returns false otherwise
     }
}
template <class Key>
bool HashTable<Key>::Insert(const Key& X)
{
     if (Search((Key&)X)) //Search if key to be inserted already exists
     {
          nSynonimous++; //Increments if a key is found
          return false; //returns false if it already exists
     }
     unsigned index = fd->hash(X); //gets the hash value from pointer to scatter function
     vData[index] = X; //sets that index of hashtable to its key
     return true; //returns true because element has been successfuly entered
}
template<class Key>
bool HashTable<Key>::Full()
{
     int count=0; // starting a variable count from 0
     for (int i = 0; i < nData; i++) // looping through whole hashtable
     {
          if (vData[i] >= -100000 && vData[i] <= 100000) //checking if the value is in right range
          {
               count++;//if it is a valid value then count will be incremented by 1
          }
     }
     return count == (nData - 1); //returns true if the count is equal to the size-1 of the hashtable.
}