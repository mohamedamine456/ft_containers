# ft_containers

In C++ STL (Standard Template Library), 3 things are meaningful and important:

1. Containers: These are used to manage a collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).
2. Algorithms: These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.
3. Iterator: These are used to step through the elements of collection of objects (aka containers).

The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".

- The data is held and managed by the `Container` classes.
- The operations over the containers are defined and managed by the configurable algorithms.

So, if `Container` classes and algorithms are completely different entities, there has to be a bridge between them, right? There has to be a dedicated tunnel between them, there has to be some kind of glue between them. Yes, you are right <=====> Iterators are those Bridge/Tunnel/Glue.

Someone might argue that STL concepts of Container/Algorithm/Iterator contradicts with the fundamental ideas of Object-Oriented Programming: The STL separates the Data and the Operations (Algorithm) over it <---> rather than combining them. The beauty and flexibility of this design is you can almost bind up every kind of container with every kind of algorithm (by kind of algorithm, I mean to say - Modifying/Non-modifying/Mutating/Sorting/Numeric etc.)

[Containers in C++ STL (Standard Template Library) - GeeksforGeeks](https://www.cplusplus.com/reference/stl/)

## Vectors in C++ STL:

`vector` one of the sequence containers, meaning the data is reliably ordered.  Vectors are as same dynamic arrays they use contiguous storage locations for their elements, which means you can access any element with an integer index in constant time.

[vector - C++ Reference](https://cplusplus.com/reference/vector/vector/)

[vector (classe)](https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-160&viewFallbackFrom=vs-2019)

### Allocator:

[std::allocatpr() in C++ STL](https://www.cplusplus.com/reference/memory/allocator/)

### Iterators:

[Iterators in C++ STL](https://www.cplusplus.com/reference/iterator/)

[Bidirectional Iterator](https://www.cplusplus.com/reference/iterator/BidirectionalIterator/)

[Random Access Iterator](https://www.cplusplus.com/reference/iterator/RandomAccessIterator/)

### Explicit constructors :

Constructors are functions with the same name as the class. They are used to create the instance of a class. They are provided default by the compiler. But still, the user can have his/her own constructor declared. We can have a constructor with a single parameter and use this kind of constructor for doing type conversion or implicit conversion.

```cpp
#include <iostream>

class A
{
	int data;
	public:
		A(int a) : data(a){
		    cout<<"A::Constructor...\n";
		};
	friend void display(A obj);
};

void display(A obj){
    cout<<"Valud of data in obj :="<< obj.data<<endl;
}

int main(void)
{
	A a = 98;
  // A a1(99);
  // display(a1);
	display(1000);
	return (0);
}
```

A declaration like below in this example is called as an **Implicit Conversion** and calls A(int a) constructor to create an A object from the integer value

[Implicit conversions](https://en.cppreference.com/w/cpp/language/implicit_conversion)

To avoid all such confusions that happen with Implicit Conversion and Constructor Conversion, we can use **explicit** keyword in constructor declaration. This forces the compiler not to do an implicit conversion and throws an error for this kind of code. And thus make sure the constructor is explicitly called with the right syntax. This keyword is used only for the constructors.

## enable_if:

[C++ Tutorial => enable_if](https://www.cplusplus.com/reference/type_traits/enable_if/)

## Stack  in c++ STL :

A stack is a data structure that operates based on LIFO (Last In First Out) technique. The std::stack allows elements to be added and removed from one end only.

The std::stack class is a container adapter. Container objects hold data of a similar data type. You can create a stack from various sequence containers. If no container is provided, the Deque container will be used by default. Container adapters don’t support iterators, so they can’t be used to manipulate data.

[stack - C++ Reference](https://www.cplusplus.com/reference/stack/stack/)

## Map in C++ STL :

### Binary Search Tree:

[Binary Search Trees (BST)](https://algorithmtutor.com/Data-Structures/Tree/Binary-Search-Trees/)

### Red Black Tree:

[Red Black Trees](https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/)

[Red Black Tree - Videos](https://www.youtube.com/watch?v=nMExd4DthdA&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=66)

[Map](https://www.cplusplus.com/reference/map/map/)

## Set in C++ STL:

[Set](https://www.cplusplus.com/reference/set/set/)