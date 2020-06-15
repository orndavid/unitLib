/**
   Template definitions for the unitLib library
 */

// Perhaps this filestructure should be renamed BaseClasses
#ifndef _UNITLIB_TEMPLATES_H__
#define _UNITLIB_TEMPLATES_H__

#include <iostream>
#include <algorithm> // std::swap
#include <memory> // Pointers
#include<vector>

// double ZERO{0.0};

// template<typename T>
// class Base{
//   T value_;
//   std::string unit_;
//   // We should add a pointer to a vector of data to hold
//   // so that the object can handle multiple values...
// public:

//   Base() : value_{(T) ZERO}{};
//   Base(T x) : value_{x}{};
//   //~Base(){std::cout << "Base destructor called\n";};

//   // Copy constructor
//   template<typename M>
//   M& operator =(const & other);
//     // Copy assignment
//   void operator=(Base& other);
//     // Move assignment
//   // Base& operator=(Base other) const;
//   // Base& operator=(Base&& other) const;
//   // // Overload cout for fine printing
//   Base& operator +=(const Base& rhs);
//   Base& operator +(const Base& rhs);
//   template<typename W>
//   friend std::ostream& operator << (std::ostream& os,  Base<W>& e);

//   /**
//    */
//   void set_unit(std::string unit){unit_=unit;};

//   T value(){return value_;};
//   virtual std::string unit() {return unit_;};

// };


// template<typename T>
// std::ostream& operator << (std::ostream& os,  Base<T>& e)
// {
//   return os << e.value_ << " " << e.unit();
// }

// // Copy constuctor
// template<typename T>
// Base<T>&  Base<T>::operator= (const Base<T>& other)
// {
//   if(this != &other)
//     {
//       value_ = other.value_;
//       unit_ = other.unit_;
//     }
//   return *this;
// }
// //Copy assignment
// template<typename T>
// void Base<T>::operator=(Base<T>& other)
// {
//   value_ = other.value();
// }


// // template<typename T>
// // void Base<T>::operator=(Base<T>&& other)
// // {
// //   value_ = other.value();
// // }



// // // Move assignment
// // template<typename T>
// // Base<T>& Base<T>::operator=(Base<T> other) const
// // {
// //   unit_ = std::move(other.unit_);
// //   value_ = std::move(other.value_);
// //   return *this;
// // }

// // template<typename T>
// // Base<T>& Base<T>::operator=(Base<T>&& other) const
// // {
// //   unit_ = std::move(other.unit_);
// //   value_ = std::move(other.value_);
// //   return *this;
// // }


// template<typename T>
// Base<T>& Base<T>::operator +=(const Base<T>& rhs)
// {
//   value_ += rhs.value_;
//   return *this;
// }

// template<typename T>
// Base<T>& Base<T>::operator +(const Base<T>& rhs)
// {
//   value_ += rhs.value_;
//   return *this;
// }

template<typename T>
class Base
{
  std::shared_ptr<T> _data;
  std::string _unit;

public:
  // Constructors and deconstructors
  Base(std::string _unit_) : _data(std::make_shared(T(0.0))),
                            _unit(_unit_){};

  Base(std::string _unit_, T _value_) :
    _data(std::make_shared<T>(_value_)),
    _unit(_unit_){};

  ~Base(){};


  /**
      @func data
      @descr Returns the data value
      @returns The vvalue that the data pointer points to
  */
  T data(){ return *_data;};
  /**
     @func data_ptr
     @descr This function returns a data pointer to the current data value
     @returns The data pointer that the base class holds
   */
  std::shared_ptr<T> data_ptr(){return _data;};
  /**
     @func  unit
     @descr Returns a string referring to the unit value of current type
     @returns A string to the defined data type
  */
  std::string unit(){return _unit;};

  // TODO finish this type
  // Copy constructor
  // Here it becomes more nuanced. Do we copy the data over, do we create a new one?

  int size();


  void set_data_by_ptr(std::unique_ptr<T> _data_);
  void conversion(T conv_factor){ *_data*conv_factor;};

  template<typename W>
  friend std::ostream& operator << (std::ostream& os,  Base<W>& e);
};


template<typename W>
std::ostream& operator << (std::ostream& os,  Base<W>& e)
{
  return os << e.data() << " " << e.unit();
}

template<>
inline std::ostream& operator << (std::ostream& os,  Base<std::vector<double>>& e)
{
  for(auto x: e.data())
    os << x << " " << e.unit() << "\n";
  return os;
}

template<>
inline std::ostream& operator << (std::ostream& os,  Base<std::vector<float>>& e)
{
  for(auto x: e.data())
    os << x << " " << e.unit() << "\n";
  return os;
}


template<>
inline int Base<float>::size(){
  return 1;
}

template<>
inline int Base<double>::size(){
  return 1;
}

template<typename T>
int Base<T>::size(){
  return this->_data->size();
}

#endif //_UNITLIB_TEMPLATES_H__
