/**
   Definiations for the base template part of the library
   can't use because we can't include unitlib_templates.h again, however,
   it being a template library we shouldn't need this anyway.
 */
#include <memory>
#include <vector>
#include "unitLib_templates.h"

template<typename T>
void Base<T>::set_data_by_ptr(std::unique_ptr<T> data_ptr)
{
  // Empty current memory so it won't get lost
  _data = nullptr;
  // Re-assign the pointer to point to the same thing as the
  // new input pointer
  _data = data_ptr;
}

