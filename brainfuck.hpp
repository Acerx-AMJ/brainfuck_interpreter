#ifndef BRAINFUCK_HPP
#define BRAINFUCK_HPP

#include <iostream>
#include <string>
#include <unordered_map>

inline void run_brainfuck(const std::string& input) {
   std::unordered_map<int, unsigned char> memory;
   int pointer = 0;
   
   for (int i = 0; i < input.size(); ++i) {
      const auto& ch = input.at(i);
      if (ch == '>') {
         ++pointer;
      } else if (ch == '<') {
         --pointer;
      } else if (ch == '+') {
         ++memory[pointer];
      } else if (ch == '-') {
         --memory[pointer];
      } else if (ch == '.') {
         std::cout << memory[pointer];
      } else if (ch == ',') {
         std:: cin >> std::noskipws >> memory[pointer];
      } else if (ch == '[') {
         if (memory[pointer] != 0) {
            continue;
         }
         int depth = 1;
         for (++i; i < input.size() && depth > 0; ++i) {
            if (input.at(i) == '[') {
               ++depth;
            } else if (input.at(i) == ']') {
               --depth;
            }
         }
      } else if (ch == ']') {
         if (memory[pointer] == 0) {
            continue;
         }
         int depth = 1;
         for (--i; i >= 0 && depth > 0; --i) {
            if (input.at(i) == '[') {
               --depth;
            } else if (input.at(i) == ']') {
               ++depth;
            }
         }
      }
   }
}

#endif
