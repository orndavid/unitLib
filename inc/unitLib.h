/** unitLib.h
   Unit conversion library API
   Author: David Orn, orn.david@gmail.com

   This takes care of unit conversion from one to another and, further, ensure unit type
   to be strong


   WARNING : kg to lbs and lbs to kg does not have high accuracy.
*/
#ifndef _UNITLIB_H__
#define _UNITLIB_H__
#include "unitLib_templates.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>


enum {
      mass,
      temperature,
      force,
      electricity,
      flow  //?
};


template<typename T>
class kg : public Base<T>
{
  int _field {mass};
  const float lbs_conv{2.20462};
public:
  // Constructors
  kg(): Base<T>("kg", (T)0.0){};
  kg(T value) : Base<T>("kg", value){};
  ~kg(){};

  // Move semantics


  // conversion factors

  T as_mg() {return this->data()*1000;};
  T as_tonne() {return this->data()/1000;};
  T as_lbs() {return this->data()*lbs_conv;};

  // Misc
  int field() {return _field;};

};


template<typename T>
class lbs : public Base<T>
{
  const float kg_conv{0.453592};
  int _field {mass};
public:
  // Constructors
  lbs(): Base<T>("lbs", (T)0.0){};
  lbs(T value) : Base<T>("lbs", value){};
  ~lbs(){};

  // Move semantics


  // conversion factors

  T as_mg() {return this->data()*1000*kg_conv;};
  T as_tonne() {return this->data()/1000*kg_conv;};
  T as_kg() {return this->data()*kg_conv;};

  // Misc
  int field() {return _field;};
};


template<typename T>
class C_deg : public Base<T>
{
  const float kelvin_conv{0.453592};
  int _field {temperature};
public:
  // Constructors
  C_deg(): Base<T>("C_deg", (T)0.0){};
  C_deg(T value) : Base<T>("C_deg", value){};
  ~C_deg(){};

  // Move semantics


  // conversion factors
  // Misc
  int field() {return _field;};
};



#endif //_UNITLIB_H__
