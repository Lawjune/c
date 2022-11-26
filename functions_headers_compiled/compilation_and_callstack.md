## Functions Prototypes

**C complier is a one-pass complier**

- _Variables, functions must-be declared before they are used._
- _Function prototypes allow you to use a function before it is defined._
- _Java compiler is a two-passes compiler, first to pass name definitions, second to pass the process._

## Stages of Compilation

**source.c**
->
[preprocessor] (-E)=> _C code, strip out comments, handles # directives, comments._

Copy the header files content of #include
The header files usualy only contain the prototypes, for the purpose of let compiler know the delarations first

=>**preprocessed C code**
->
[compiler] (-S)=> _Assembly code (.s)_

=> **Assembly**
->
[assembler] (-C)=> _Binary code / Object code (.o)_

=> **Object code**
**C standard library** <=
**Math library** <=
**...other libraries if applicant**<=
->
[linker]
->
**executable**

## Header Files (.h)

- **Included other headers**
- **Constants**
- **Type declarations**
- **Function prototypes**

## Call Stack

**Memory Map**
[4GB -------------------- 0]

---4G

[Stack Segment](read-write)
[local variables]

[FREE MEMORY]

[data segment](read-write)
[heap][global variables]

[text segment](read-only)
[global constants][program codes]

---0

_Every program thinks it is the only one program running and occupying the whole memory._

https://pythontutor.com/

## Assignment - 1

The signmoid function is used frequently in artificial intelligence "deep learning" algorithms as an approximation of the activateion of a biological neuron. A neuron receives an electrochemical from its dendrities. The signal enters the nucleus, which is activated if the signal is stronger than a certain threshold. The output is then sent along the axon to other neurons.

https://my.clevelandclinic.org/health/body/22974-myelin-sheath#:~:text=A%20myelin%20sheath%20is%20a,a%20neuron%20called%20the%20axon.

In an AI algorithm, hundreds to thousands of artificial neurons are connected togther fo form an artificial neural network (ANN).

In its simplest form, an artificial neuron can use a step function to emulate activation. However,a sigmoid function, is a better approximation of what goes on biologically.

https://en.wikipedia.org/wiki/Sigmoid_function

sigmoid(x) = 1 / (1 + exp(-x))

## Assignment - 2

https://en.wikipedia.org/wiki/Collatz_conjecture

## Random Number Generator

**Von Neumann RNG**

1. Start with a 4-digit number as seed.
2. Square it.
3. Extract middle 4 digits. -> Random number.
4. Use it as the seed for the next iteration.

1526 -> square() -> 2_328_676
-> extract_4_digits() -> 3286
-> square() -> 10798896
-> extract_4_digits() -> 7977

12345 / 100 = 123 -> Get rid of 2 not needed digits.
12345 % 100 = 45 -> Remain the digits needed.
