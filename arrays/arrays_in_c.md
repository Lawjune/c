## Differences against Java

```java
int[] nums = new int[10];
```

```c
int nums[10];
```

**Differences between Java and C**

    - In C, the array is a local variable.
    - When you go out of scope, the array will disappear.

## Basic Syntax of Arrays in C

_Create an array of 20 doubles, called ages._

```c
double ages[20];
```

_Create an array of 50 blaps, called blop._

```c
blap blop[50];
```

_Create an array of 1000 pixels, called img._

```c
pixel img[1000];
```

_What are the indices of the ages array?_
0 ... 19

_Assign the number 15 to element 0 of nums._

```c
nums[0] = 15;
```

_Copy element 0 of nums into element 3._

```c
nums[3] = nums[0];
```

_Print out element 3 of nums._

```c
printf("%d", nums[3]);
```

**Arrays are laid out in contiguous memory.**

```c
void input_array(int arr[], const int length)
```
