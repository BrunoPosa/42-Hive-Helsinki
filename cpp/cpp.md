------ in ex=========
C++ principles/to do list for good code:
=========
-RAII (Resource Acquisition Is Initialization): C++ emphasizes the RAII pattern, where resources like memory and file handles are acquired during object creation and automatically released when objects go out of scope.

 encapsulation, inheritance, polymorphism, and abstraction

== resources:
-slowly readding: Programming: Principles and Practice Using C++ by the creator of c++
-https://theswissbay.ch/pdf/Gentoomen%20Library/Programming/C%2B%2B/Addison%20Wesley%20-%20C%2B%2B%20by%20Dissection.pdf


'#pragma once' is the same as '#ifndef CPP_H \n #define CPP_H \n #endif'

#include <stdio.h> vs #include <iostream> C headers ususally have .h and Cpp headers usually don't have any extension. C standard lib vs C++ standard lib difference. 



===== names ======

- '::' scope resolution operator - highest precedance operator in cpp


One mac i checked has c++ version that supports c17, and clang version that supports c14. Carlos later told me our school PCs use c++ as an alias for clang, so i guess by default we use C++ 14 standard here. But the Macs support C++17 fully as well, and mostly C++20 but with incomplete features. On other non-hive computers, c++ compiles with gcc or g++? 
```
% c++ --version
Ubuntu clang version 12.0.1-19ubuntu3
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```



string	getType() const; <-- the 'trailing' const means the object calling the getType will not be modified. 



=================================================
CPP 00 - Namespaces, classes, member functions, stdio streams, initialization lists, static, const, etc
=================================================


======= basic meanings - ex00 ========

- namespaces limit identically named variables' scopes
- Classes are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members.
- An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.
- classes and structs are similar
- struct member functions are called just that, but often reffered to as 'methods', and methods get struct member variables passed to them implicitly. There is more to real methods, i guess?
- everything in a struct after 'private:' cannot be accessed from outside the struct but needs a method to touch it.
- A class is the same as a cpp struct, technically, but by default everything in a class is private. As a difference to C structs, classes can have functions. The important difference is the usage: "Basically all existing coding-standards agree that everything that consists of more than a few trivial public members and maybe some simple methods should be a class. Since it is generally considered a good idea to put the public interface first this ends up with the somewhat ironic situation that most classes start with public:."
 
-A constructor is a function that is called upon the construction of an object to initialize it's state correctly. Many languages have this feature. C++ is however one of the relatively few languages that also have the opposite: A destructor.

A destructor is a function that will run whenever an object ceases to exist. It's main purpose is to clean up any resources that the object might own in.

- character output cout include <iostream> std::cout << "Hello world\n" part of global namespace (::) std. std::cerr - prints to stderr. << std::endl is a portable way to add a newline, and this one should also flush the buffer. 

- "As we see the objects that are constructed first get destructed last. This is guaranteed by the standard and quite important: Assume we want acquiring multiple resources, where some cannot exist without others already existing; thanks to the guaranteed order of destruction no object will cease to exist while other, later constructed ones, might still need it. This technique is called “Resource Acquisition Is Initialization” (RAII) and that it is one the most important techniques of C++. Some people call it C++'s greatest feature"

-Member attributes are just member variables in a class.

-this-> is a pointer to the current instance

Practical, related to exercise:
https://en.cppreference.com/w/cpp/string/byte/toupper
- Tidbit: i don't think i need to use counter overflow protection for int i and k counters as the arg_max of the ubuntu is set to 2 million arguments, and likely bash has another limit before that. 

---- ---- 
Encapsulation pros:
-Data Hiding: Internal data is kept private, preventing direct modification from outside the class.
-Controlled Access: Public methods (getters and setters) are used to interact with the private data, ensuring data integrity and validation.
-Improved Maintenance: Changes to the internal structure of the class don't affect external code as long as the public interface remains the same.
---- ---- 


========= ex01 ==========

- initialization list is the : after a class constructor, and it uses direct initialization, instead of by default the class constructor with empty init. list, which would use initialization by value twice? So supposedly more efficient than initializing inside the constructor body. 
- Members are always initialized in the order they are declared in the class, not the order they appear in the initialization list, so careful! Bc this can lead to undefined behavior if init.list is in wrong order.
- type specifier is 'int', 'double' etc in front of variable. Type modifiers are 'signed', 'unsigned', 'long', 'short'; Type qualifiers are 'const', 'mutable', 'volatile'. A SPECIFIER SEQUENCE combines keywords (like const, volatile, unsigned, etc.) and type specifiers (like int, char, float, etc.) to describe the exact nature of the type being declared.
-"A class in C++ is an extension of the idea of struct found in C. A class packages a data type with its associated functions and operators. This in turn can be used to implement abstract data types (ADTs). An abstract data type, such as a stack, is a set of values and operations that define the type A large part of the object-oriented programming (OOP) design process involves thinking up the appropriate ADTs for a problem."


===
Eval lessons:
-Must not print to stderr!
-Use string or upper in ex00 instead of toupper and going char by char!
-Default constructor can be totally omitted from the class. I knew it can be omitted from the class definitino if I specify it as Contact() = default; but it can actually fully be omitted (obviously in case there are no primitive members and there is another constructor for the string members).
--"You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards"
-When i saw the "extra" Account files on intra, I went to google to research the names and people coding that, and then posted a question in Discord. I could have simply revisited the subject and noticed the exercise I did not do which was not mandatory. 
-I think i did not equip the ex01 program to take in redirection from /dev/random or another infinite stream. I guess that could have been handled by handling the instream in chunks (using std::cin.read)
===





=================================================
CPP 01
=================================================

-if newZombie() doesn't need to access any instance-specific data (like _name), it should be declared as a static member function. Static member functions belong to the class rather than any specific instance, so you can call them using the class name.

-class members are by default private; if not explicitly set to protected or public. This behaviour promotes encapsulation. 

-Most implementations of std::string can store small strings (typically up to 15–23 characters, depending on the platform) in a statically allocated internal buffer. For small values of int, this optimization means no dynamic memory allocation is required, so exceptions like std::bad_alloc are avoided. So, I don't check for 'malloc failures' in std::to_upper(int) if i am using ints. 

-Calling delete[] on a nullptr is safe in C++, and it does nothing. Although it is safer to call delete[] when there is a validly allocated pointer to mallocd memory.

-huh, funny. When i write : ```Zombie z; z = Zombie("John")```, there is two objects, and the first 'z' gets destroyed when we assign it the constructor Zombie(name).

------References a la GPT: Alias for a variable:
    -A reference acts as an alternative name for a variable.
    	Any operation on the reference directly affects the original variable.
	-Must be initialized at declaration:
	    You must assign a reference to an existing variable when you declare it.
	-Cannot be null:
	    Unlike pointers, references must always refer to a valid object.
	-No reseating:
    	A reference cannot be changed to refer to another variable after initialization.



------------the main practical difference between a struct and a class in cpp is its access control:
	-the struct has members public by default, inheriting also public by default
	-class has private by default, inheriting private as well. 
	Use struct when you primarily want a simple, data-holding object without requiring encapsulation
	or advanced features (although you can use access control and functions in structs.
	Use class when you want to define a more complex type with encapsulation, access control,
	or when you're implementing object-oriented features like inheritance or polymorphism.


------ in ex04 i had class private memnber variables string& type, instead of just string. That caused issues where the scope wouild exit and i'd be using dangling string pointers with garbage values. 







=================================================
CPP 02 - Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class form
=================================================







====================================================
CPP 03 - Inheritance
====================================================
--------Inheritance - The capability of a class to derive properties and characteristics from another class 
class  derived_class_name : access-specifier  base_class_name
{
       //    body ....
};

Inheritance Modes:
-If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.

-If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become protected in the derived class.

-If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become private in the derived class. They can only be accessed by the member functions of the derived class. Private mode is the default mode that is applied when we don’t specify any mode.



-------Virtuality- Geeks for geeks - (seems like Templates might be a better alternative)
A virtual function (also known as virtual methods) is a member function that is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the method.

    Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call.
    They are mainly used to achieve Runtime polymorphism.
    Functions are declared with a virtual keyword in a base class.
    The resolving of a function call is done at runtime.

Rules for Virtual Functions:
    Virtual functions cannot be static.
    A virtual function can be a friend function of another class.
    Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
    The prototype of virtual functions should be the same in the base as well as the derived class.
    They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
    A class may have a virtual destructor but it cannot have a virtual constructor.
    
    


Grok3:
Key Rule in C++: If a base class destructor is virtual, all derived class destructors are automatically virtual, regardless of whether the virtual keyword is used in the derived class declaration. This is because the virtual nature of the destructor is inherited.


====================================================
CPP 04 - Subtype polymorphism, abstract classes, interfaces
====================================================





