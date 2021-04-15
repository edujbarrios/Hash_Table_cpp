#pragma once
template <class Key>
class ScatterFunction {
public:
     virtual unsigned operator () (const Key& k) const = 0;
     virtual unsigned hash(const Key& k) = 0;
};