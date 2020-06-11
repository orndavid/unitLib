/**
   Template definitions for the unitLib library
 */

#ifndef _UNITLIB_TEMPLATES_H__
#define _UNITLIB_TEMPLATES_H__

#include <iostream>

template<typename T>
class Base{
  T value;
 public:
  Base(T value_) : value {value_} {};
  T get_value(){return value;};
  friend std::ostream & operator <<(std::ostream &os, const Base &base);
};


#endif //_UNITLIB_TEMPLATES_H__
