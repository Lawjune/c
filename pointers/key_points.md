## \* is used in 3 different ways

- Multiplication
- Declaration of a variable that variable is a pointer
- Expression
  - "Derefernce" of a pointer
    d

## Sumary

- **To declare a pointer**

```c
int *x;
```

- **To get the address of a variable**

```c
&i
```

- **To derefernce a pointer in a expression**

```c
*x // Go to the address of variable x points to
```

- **To pass a pointer to a function**

```c
f(&i)
```

**Arrays are known by their address**

```c
int arr[4];
```

- The value of arr is the address of the first element
- To pass an array to a function just use the variable name, because it is already an address (pointer).
- To receive an array, either use array declaration or use pointer declaration.

```c
f(int[]);
f(int *x);
```

## Function Pointer in C

A function is a block of instructions with a name.
It exists somewhere in memory.

A pointer to the function is just the address of where the instructions start.

**Example**

```c
int foo(int x)
```

`foo` is the address of foo (so is &foo)
_To assigne foo to a variable, declare it like this?_

```c
int (*bar) (int x) foo;
```

`int` => the function returns an int
`(*)` => it's a pointer to a function
`(bar)` => name of var
`(*bar)` => the pointer points to function
`(int x)` => parameters

**Calling a function through its pointer**
To call the function, just use the variable as if it was the function name. Derefernce is done for you.

Both foo and bar point to the ame block of code.
