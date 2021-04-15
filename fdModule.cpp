#pragma once
#include "ScatterFunction.h"
template <class Key>
class fdModule : public ScatterFunction <Key> {
public:
     fdModule(const unsigned n) : nData(n) {}
     unsigned operator () (const Key& k) const {
          return k % nData;
     }
     unsigned hash(const Key& k)
     {
          return k % nData;
     }
private:
     unsigned nData;
};