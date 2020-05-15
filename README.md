# Monty Interpreter

Monty 0.98 is a scripting language that is first compiled into Monty byte code (just like in Python). It relies on a unique stack, with specific instructions to manipulate it.

The goal of this project is to create an interpreter for Monty ByteCode files, utilizing Stacks (LIFO) and Queues (FIFO). Also included are [BrainFuck](https://en.wikipedia.org/wiki/Brainfuck) files.



## Quick Start

<u>Monty</u>:

Simply Compile: `$ gcc *.c -o monty`

Then Run: `$ ./monty filename.m`

A sample bytecode file is located at `/bytecodes/test.txt`.







## Commands Overview

The Monty Interpreter will tokenize command inputs, ignoring all whitespaces and comments which start with a `#` sign. When tokenizing, the interpreter only looks at the first 2 inputs per line.

Potential failures and their messages will be mentioned for each operation. Failures that can occur at this time include:

- USAGE: monty file      *# If given no file or too many arguments*
- Error: Can't open file <file name>      *# If given invalid file*
- Error: unknown instruction <opcode>      *# If unknown operation given*
- Error: malloc failed      *# if malloc fails*



There are 17 valid operation codes:

1. **push**

   Push only valid integers into the doubly linked list. Defaults to a Stack LIFO status.

   Given:

   ```
   $ cat test.m
   push 1
   push 2
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   2
   1
   ```

   Failures:

   - Error: usage: push integer      *# if no argument given or invalid argument*

   ​


1. **pall**

   Print the values within the linked list.

   ​

2. **pint**

   Print only the value at the top of the linked list (head of linked list).

   Given:

   ```
   $ cat test.m
   push 1
   push 2
   pint
   ```

   Expected:

   ```
   $ ./monty test.m
   2
   ```

   Failures:

   - Error: can't pint, stack empty      *# If linked list is empty, can't print*

   ​

3. **pop**

   Remove the top element of the linked list.

   Given:

   ```
   $ cat test.m
   push 1
   push 2
   push 3
   pop
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   2
   1
   ```

   Failures:

   - Error: can't pop an empty stack      *# If linked list is empty*

   ​

4. **swap**

   Swap the top 2 elements of the linked list.

   Given:

   ```
   $ cat test.m
   push 1
   push 2
   swap
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   1
   2
   ```

   Failures:

   - Error: can't swap, stack too short      *# must have at least 2 elements*

   ​

5. **add**

   Add the top 2 elements of the linked list and store as the new head of the linked list.

   Given:

   ```
   $ cat test.m
   push 1
   push 2
   add
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   3
   ```

   Failures:

   - Error: can't add, stack too short      *# must have at least 2 elements*

   ​

6. **nop**

   This operation doesn't do anything.

   Given:

   ```
   $ cat test.m
   push 1
   nop
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   1
   ```

   ​

7. **sub**

   Subtract the top element of the linked list from the second top element of the linked list.

   Given:

   ```
   $ cat test.m
   push 1
   push 2
   sub
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   -1
   ```

   Failures:

   - Error: can't sub, stack too short      *# must have at least 2 elements*

   ​

8. **div**

   Divide the second top element of the stack by the top element of the stack.

   Given:

   ```
   $ cat test.m
   push 20
   push 10
   div
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   2
   ```

   Failures:

   - Error: can't div, stack too short      *# must have at least 2 elements*
   - Error: division by zero      *# cannot divide by 0*

   ​

9. **mul**

   Multiply the top 2 elements in the linked list and store as the new head of the linked list.

   Given:

   ```
   $ cat test.m
   push 2
   push 3
   mul
   pall
   ```

   Expected:

   ```
   $ ./monty test.m
   6
   ```

   Failures:

   - Error: can't mul, stack too short      *# must have at least 2 elements*

   ​

10. **mod**

    Uses the modulus of the second top element of the linked list by the top element of the linked list. The new value is stored as the new head.

    Given:

    ```
    $ cat test.m
    push 7
    push 3
    mod
    pall
    ```

    Expected:

    ```
    $ ./monty test.m
    1
    ```

    Failures:

    - Error: can't mod, stack too short      *# must have at least 2 elements*
    - Error: division by zero      *# cannot divide by 0*

    ​





## File Descriptions

- `monty.h` - Header file which contains library includes, structs created, and all function prototypes.
- `main.c`  - Main monty file handling the core operations, including reading user input arguments, opening bytecode file, parsing inputs, and calling correct operations.


## Team

 [DT Van](https://github.com/dtvangogh)