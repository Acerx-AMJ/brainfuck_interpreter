// This file is shorter, but it does not support reading a file and does
// not check the argument count.

#include <iostream>
#include <unordered_map>

int main(int argc, char* argv[]) {
   std::string input (argv[1]);
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
         std::cin >> std::noskipws >> memory[pointer];
      } else if (ch == '[' && memory[pointer] == 0) {
         int depth = 1;
         for (++i; i < input.size() && depth > 0; ++i) {
            depth += (input.at(i) == '[') - (input.at(i) == ']');
         }
      } else if (ch == ']' && memory[pointer] != 0) {
         int depth = 1;
         for (--i; i >= 0 && depth > 0; --i) {
            depth += (input.at(i) == ']') - (input.at(i) == '[');
         }
      }
   }
}
