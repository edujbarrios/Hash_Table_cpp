#pragma once
#include "ScatterFunction.h"
template <class Key>
class HashTable
{
     int nData; //For storing the number of items in hashtable
     Key *vData; //Actual Hash Table
     ScatterFunction<Key>* fd; //Scatter or Dispersion function pointer
     int nSynonimous = 0; // Indicates the number of keys found during search process.
public:
     HashTable(int size, ScatterFunction<Key>* f); //Constructor for setting values of size and pointer to the scatter function
     bool Search(Key& X)const; // Searching an element X in the Hash Table
     bool Insert(const Key& X); //Inseting an element X in the Hash Table
     bool Full(); //returns true if hashtable is full returns false otherwise
};

