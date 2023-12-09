# security-oop-c
This project was completed by myself for my computer security class assignment. Templates for `Int.h` and `GenericTraits.h` were provided by the instructor for guidance, as was `CMakeLists.txt`.

## overview
For this assignment, I was tasked with integrating a quicksort function that could apply to any of the four structs: `Int`, `Student`, `Human`, and `Rectangle`.
This task required for an implementation of basic object-oriented programming (OOP) in C, a language that does not inherently support such concepts.
This project is heavily focused on pointer and memory operations, yet is tested to be memory safe when compiled with AddressSanitizer.
The code also pushed me to better understand the definition and usage of C macro preprocessing (Most notable are lines 48 to 57 in GenericTraits.h).

An `Interface` in OOP is a contract that defines a set of methods that a class must implement. In my code, the `Generic Traits` struct acts as an interface for the four datatypes,
defining the `new`, `dump`, `cmp`, and `drop` function pointers for each datatype to "attach" its own functions to. This serves similarly to v-tables in C++.
Through the use of this interface, I am able to call the same quicksort function on the different structures, demonstrating polymorphism.
A struct combined with an interface like so has effectively created an encapsulated class with bundled methods.
Through my particular task, I have also demonstrated the OOP concept of inheritance by linking the `Student` to the existing `Human` datastructure.

## compilation instructions
Download repository contents into your desired directory.

`mkdir build` From this main directory, create a build folder to `cd` into.

`cmake -DCMAKE_BUILD_TYPE=asan ../src` configures CMake with ASan enabled.

`make`, then `./Main [input_filename.txt]` or `./Main [arguments...]` to build then run the code.
