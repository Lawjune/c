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
