// Made by WafflesExploits
#include <iostream>
#ifndef PYTHON_PRINT_H
#define PYTHON_PRINT_H

// Helper function to find the next "{}" placeholder in the format string
const char* find_placeholder(const char* format) {
   while (*format) {
      if (*format == '{') {
         if (*(format + 1) == '{') {
            // Escaped '{', skip both
            format += 2;
            continue;
         }
         if (*(format + 1) == '}') {
            return format;
         }
      }
      else if (*format == '}') {
         if (*(format + 1) == '}') {
            // Escaped '}', skip both
            format += 2;
            continue;
         }
      }
      ++format;
   }
   return nullptr;
}

// Base case: No arguments left to replace
void print_helper(const char* format) {
   const char* brace = find_placeholder(format);
   if (brace) {
      // Print up to the first remaining placeholder
      while (format < brace) {
         if (*format == '{' && *(format + 1) == '{') {
            std::cout << '{';
            format += 2;
         }
         else if (*format == '}' && *(format + 1) == '}') {
            std::cout << '}';
            format += 2;
         }
         else {
            std::cout << *format++;
         }
      }
      // Indicate missing arguments
      std::cout << "\n[!] Error: Missing arguments" << std::endl;
      return;
   }
   // No placeholders left, just print the remaining string
   while (*format) {
      if (*format == '{' && *(format + 1) == '{') {
         std::cout << '{';
         format += 2;
      }
      else if (*format == '}' && *(format + 1) == '}') {
         std::cout << '}';
         format += 2;
      }
      else {
         std::cout << *format++;
      }
   }
   std::cout << std::endl;
}

// Recursive case: At least one argument to replace
template<typename T, typename... Args>
void print_helper(const char* format, const T& first, const Args&... args) {
   const char* brace = find_placeholder(format);
   if (brace) {
      // Print characters up to the placeholder, handling escaped braces
      while (format < brace) {
         if (*format == '{' && *(format + 1) == '{') {
            std::cout << '{';
            format += 2;
         }
         else if (*format == '}' && *(format + 1) == '}') {
            std::cout << '}';
            format += 2;
         }
         else {
            std::cout << *format++;
         }
      }

      // Replace "{}" with the current argument
      std::cout << first;

      // Move past the "{}"
      format += 2;

      // Recurse with the remaining format string and arguments
      print_helper(format, args...);
   }
   else {
      // No more placeholders but still arguments left
      while (*format) {
         if (*format == '{' && *(format + 1) == '{') {
            std::cout << '{';
            format += 2;
         }
         else if (*format == '}' && *(format + 1) == '}') {
            std::cout << '}';
            format += 2;
         }
         else {
            std::cout << *format++;
         }
      }
      std::cout << "\n[!] Error: Extra arguments provided" << std::endl;
   }
}

// The main print function
template<typename... Args>
void print(const char* format, const Args&... args) {
   print_helper(format, args...);
}

#endif // !PYTHON_PRINT_H
