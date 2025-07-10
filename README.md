# SQUARE SOLVER

## About task

The programm solves any square equation, that user enters. The program receives 3 values as input, namely coefficients a, b, c. And the output is the roots and their number.

$$
a\cdot x^2 + b\cdot x + c = 0
$$

The solution of this equation is expressed as:

$$
x = \frac{-b \pm \sqrt{D}}{2 \cdot a}
$$

where the discriminant formula:

$$
D = b^2 - 4\cdot a\cdot c
$$

## How to use

There is Makefile in the project, so to compile all files and start the programm, you have to open a terminal and write:

```C
$ make    # compilation
$./square # run exe file
```
After start the programm makes diagnoses of system by unit tests, if all tests went well, you will be able to enter coefficients of the square equation in **order** (a, b, c) and separated by a **space**. Example:

```C
Enter your coefficients a, b, c
of square equation a*x^2 + b*x + c = 0:

4 9 3                  # a b c

or

sqrt(9) 2.4 -3         # a b c

or

-351.153 52.9 099014.1 # a b c
```

## Tools

### Unit tests

Built-in unit tests go through tester before processing users equation. If some king of test is not going well, the user will get message about error in tests, and the programm will end immidiately.

### Processing of results

All different results of the users square equation processing by returning values. Solution depends on this values like 1 root, 2 roots, etc. It organized by switch.

### Double and Float

The project except integers includes floating-point numbers.

$$
1.2345, -55.777, -153.153, ...
$$

### Taking the root of an imput number

It is possible to take the square root of any number, that user enters. The syntaxis of the command:

$$
\sqrt x \iff sqrt(x)
$$

where x is your number.
