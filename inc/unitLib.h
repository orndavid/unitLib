/** unitLib.h
   Unit conversion library API
   Author: David Orn, orn.david@gmail.com

   This takes care of unit conversion from one to another and, further, ensure unit type
   to be strong
*/
#ifndef _UNITLIB_H__
#define _UNITLIB_H__
#include <unitLib_templates.h>
#include <string>


template<class T>
class Kg : public Base<T>{
private:
  std::string unit_{"kg"};
public:
  Kg(): Base<T>(){};
  Kg(T& x) : Base<T>(x){};
  Kg(T&& x): Base<T>(x){};
  ~Kg(){};
  std::string unit(){return unit_;};
};

template<class T>
class lbs : public Base<T>{
private:
  const std::string unit_{"lbs"};
public:
  lbs(): Base<T>(){};
  lbs(T& x) : Base<T>(x){};
  lbs(T&& x): Base<T>(x){};
  ~lbs(){};

  std::string unit(){return unit_;};
  };

template<class T>
class Force : public Base<T>{
private:
  const std::string unit_{"F"};
public:
  Force(): Base<T>(){};
  Force(double& x): Base<T>(x){};
  Force(double&& x): Base<T>(x){};
  ~Force(){};

};

#endif //_UNITLIB_H__
