/**
   Template definitions for the unitLib library
 */

// Perhaps this filestructure should be renamed BaseClasses
#ifndef _UNITLIB_TEMPLATES_H__
#define _UNITLIB_TEMPLATES_H__

#include <iostream>
#include <memory>

double ZERO{0.0};

template<class T>
class Base{
  T value_;
  std::string unit_;
public:

  Base() : value_{(T) ZERO}{};
  Base(T x) : value_{x}{};
  ~Base(){};

  T value(){return value_;};
  virtual std::string unit() {return unit_;};

  template<class U>
  friend Base<U> operator +(const Base<U>& b1, const Base<U>& b2);


  // TODO figure out how to setup the + operator
  /*
  Base<T> operator +(Base<T>& rhs){
    T nval = value() + rhs.value();
    return Base<T>(nval);
  }

  Base<T> operator +(Base<T>&& rhs){
    T nval = value() + rhs.value();
    return Base<T>(nval);
  }
  */

  template<class U>
  Base<T>& operator =(Base<U>& other)
  {
    this->value_ = std::move(other->value);
    this->unit_ = std::move(other->unit);
  }

  template<class U>
  Base<T>& operator =(Base<U>&& other)
  {
    this->value_ = std::move(other->value);
    this->unit_ = std::move(other->unit);
  }


  friend std::ostream& operator << (std::ostream& os,  Base& e){
    return os << e.value_ << " " << e.unit();};
};


template<class T>
const Base<T> operator +(const Base<T>& b1, const Base<T>& b2)
{
  return Base<T>(b1.value() + b2.value());
}


#endif //_UNITLIB_TEMPLATES_H__
