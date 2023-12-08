# security-oop-c
This project was completed by myself for my computer security class assignment.

For this assignment, I was tasked with integrating a quicksort function that could apply to any of the four structs: Int, Student, Human, and Rectangle.
This task required for an implementation of basic object-oriented programming (OOP) in C, a language that does not inherently support such concepts.

An `Interface` in OOP is a contract that defines a set of methods that a class must implement. In my code, the `Generic Traits` struct acts as an interface for the four datatypes,
defining the `new`, `dump`, `cmp`, and `drop` function pointers for each datatype to "attach" its own functions to. This serves similarly to v-tables in C++.
Through the use of this interface, I am able to call the same quicksort function on the different structures, demonstrating polymorphism.
