* About
The following youtube video shows an extremely powerful method for defining unit conversion in a template library.

Source
-  https://www.youtube.com/watch?v=fWcnp7Bulc8&t=1995s

The concept the author (Barney Dellar) is working with is "Strong Types in C++", where he uses the infamous mars rover crash
"Europe's Schiaparelli Mars Lander" where the fault has been determined to be due to wrong measurement types (imperial vs
SI units).
Although changing the units is an important factor there is a greater lesson here about creating the types that you will be
working with in order to force constraints on the user.


* Build philosophy
The idea is to make this reliant only on the stdlib, this will make the code more portable and user available without much hassle.

For debugging however, we used the GoogleTests framework to unittest various aspects. 

* Building
Create a directory called build, go into new directory and run cmake ..

```shell
mkdir build && cd build
cmake ..
```

** Debug build
For development and debugging we used the GoogleTest framework, so in order to build the debug system to figure out any issues
you need to install that framework.

```shell
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=debug
```

To move back to the release build
```shell
cmake .. -DCMAKE_BUILD_TYPE=realese
```

* Special Ponters
The CMakeLists.txt file sets the -march flag to native, this might cause different architectures to fail during compilation.