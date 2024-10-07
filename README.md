# Python-Print-In-CPP
#### -> A lightweight C++ print function that combines the simplicity of printf with the flexibility of cout, enabling intuitive and type-safe formatting with minimal code.

python-print.h merges the best of both printf and cout to simplify formatted output for C++ developers. It allows you to use Python-like print syntax for easier and more intuitive string formatting.

## Table of Contents
1. [Key Features](#key-features)
2. [Installation](#installation)
3. [Usage Example](#usage-example)
4. [Error Handling](#error-handling)
5. [Contributions](#contributions)
6. [Contact](#contact)

## Key Features:

- Simple & Intuitive syntax: print("Hello, {}!", name); instead of cout << "Hello, " << name << "!".
- Automatic Formatting: Handles multiple data types seamlessly, similar to Python's f-strings.
- Lightweight: Dependency-free, utilizing only C-style strings, variadic templates, and the iostream library.
- Error Handling: Provides clear error messages for mismatched placeholders and arguments.
- Supports C++14 and above.

## Installation:
- Copy `python_print.h` into your project directory.
- Include in Your Code: `#include "python_print.h"`

## Usage Example

```
#include <iostream>
#include "python_print.h"

// Example usage
int main() {
   // Example 1: Simple replacement
   print("5 + 5 = {}", 10);
   // Output: 5 + 5 = 10

   // Example 2: Multiple replacements
   const char* greeting = "Hello";
   const char* target = "World";
   print("{} {}!", greeting, target);
   // Output: Hello World!

   // Example 3: Mixed types
   int age = 30;
   double pi = 3.14159;
   print("Age: {}, Pi: {}", age, pi);
   // Output: Age: 30, Pi: 3.14159

   // Example 4: More arguments than placeholders
   print("Only one placeholder: {}", "First", "Second");
   // Output: Only one placeholder: First [Error: Extra arguments provided]

   // Example 5: Fewer arguments than placeholders
   print("Missing arguments: {} and {}", "Only one");
   // Output: Missing arguments: Only one and  [Error: Missing arguments]

   // Example 6: Escaped braces
   print("Use double braces to include literals: {{}} and replace {}", "this");
   // Output: Use double braces to include literals: {} and replace this

   // Example 7: Escaped braces with multiple replacements
   print("Escaped braces: {{{{ and }}}} and values: {} {}", 100, 200);
   // Output: Escaped braces: {{ and }} and values: 100 200

   // Example 8: No placeholders
   print("This string has no placeholders.", 123);
   // Output: This string has no placeholders. [Error: Extra arguments provided]

   // Example 9: No arguments
   print("No arguments to replace here.");
   // Output: No arguments to replace here.

   return 0;
}
```
# Error Handling
- Extra Arguments: If more arguments are provided than placeholders, an error message is displayed.
- Missing Arguments: If fewer arguments are provided than placeholders, an error message is displayed.
- Escaped Braces: Use double braces ({{ or }}) to include literal braces in the output.

# Contributions
Contributions are welcome! Please open an issue or submit a pull request for any enhancements or bug fixes.

# Contact
Created by @WafflesExploits - You can reach me out on my socials :)
