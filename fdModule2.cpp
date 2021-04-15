#pragma once
#include "ScatterFunction.h"
template <class Key>
class fdModule2 : public ScatterFunction <Key> {
public:
     fdModule2(const unsigned n) : nData(n) {}
     unsigned operator () (const Key& k) const {
          return ((k + nData) % nData);
     }
     unsigned hash(const Key& k)
     {
          return ((k + nData) % nData);
     }
private:
     unsigned nData;
};