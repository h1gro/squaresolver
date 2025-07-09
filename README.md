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
