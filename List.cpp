#pragma once
template<class Key>
class List
{
     Key* arr;
     int size;
public:
     List(int size)
     {
          this.size = size;
          arr = new Key[size];
     }
     bool Search(Key& x)
     {
          if (arr[x % size] == x)
          {
               return true;
          }
          else
          {
               return false;
          }
     }
     bool Insert(const Key& x)
     {
          if (Search(x))
          {
               return false;
          }
          arr[x % size] = x;
          return true;
     }

};