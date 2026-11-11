# Rational Number Class (C++)

A C++ `Rational` class for exact fraction arithmetic, built as a static library and tested with GoogleTest (37 tests).

Every `Rational` is kept in **lowest terms with a positive denominator**. For example, `Rational(6, -8)` is stored as `-3/4`, and zero is always stored as `0/1`. A zero denominator throws `std::domain_error`.

## Example

```cpp
#include "rational.hpp"

Rational a(1, 2), b(3, 4);

std::cout << a + b;              // 5/4
std::cout << a * b;              // 3/8
std::cout << b - a;              // 1/4
std::cout << Rational(6, -8);    // -3/4
std::cout << Rational(0.75);     // 3/4
std::cout << double(Rational(1, 3));   // 0.333333

Rational c;
std::cin >> c;                   // input "10/4" is read as 5/2
```

## Features

| Area | What's provided |
| --- | --- |
| **Constructors** | Default (`0/1`), from an `int`, from a numerator and denominator, and from a `double` (accurate to 6 decimal places through `doubleBase = 1000000`). |
| **Accessors** | `num()` and `den()` getters, and `num(int)` / `den(int)` setters. The setters re-simplify the fraction and restore the old value if anything fails (strong exception guarantee). |
| **Arithmetic** | `+ - * /`, unary `+` and `-`, prefix and postfix `++` and `--` (add or subtract 1), and `+= -= *= /=`. |
| **Comparison** | `== != < <= > >=`, using cross-multiplication for ordering. |
| **Mixed types** | Free-function overloads let an `int` or `double` appear on the left side, such as `2 + r` and `0.5 == r`. |
| **Conversions** | `explicit operator int()` (truncates) and `explicit operator double()`. |
| **Streams** | `<<` prints `num/den`; `>>` reads `num/den` and sets `failbit` on bad input. |

Internally, `simplify` uses a recursive greatest-common-factor (`GCF`) function to reduce fractions, and addition and subtraction use the least common multiple (`LCM`) of the denominators.

## Project layout

| Path | Description |
| --- | --- |
| `rational/rational.hpp` | Class declaration and inline free-function operators. |
| `rational/rational.cpp` | Implementation. |
| `rational_test/rational.test.cpp` | GoogleTest tests for constructors, setters, arithmetic, compound assignment, comparison, conversions and I/O. |
| `CMakeLists.txt` | Top-level CMake project. Downloads GoogleTest with `FetchContent`. |
| `CMakePresets.json` | Windows build presets (x64/x86, Debug/Release). |

## Building and testing

Requires CMake 3.8 or later and a C++ compiler.

**Visual Studio:** open the folder as a CMake project, choose a preset such as **x64 Debug**, and run the tests from **Test Explorer**.

**Command line:**

```
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

## Project notes

- **Author:** Simon Diaz
- **Description:** A class that implements math, comparison and conversion operators, so `Rational` objects can be added, subtracted, multiplied and more.
- **Weaknesses:** Implementing strongly guaranteed setters. With more time, the setters would be engineered to fit that need better.
- **Strengths:** Readable code that would be easy to understand when coming back to it later.
