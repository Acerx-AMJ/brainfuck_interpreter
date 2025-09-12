#include <iostream>
#include <fstream>
#include <unordered_map>

int main(int argc, char* argv[]){
   if (argc != 2) {
      std::cerr << "Expected two args, got " << argc << " instead.\n";
      return -1;
   }
   std::ifstream file (argv[1]);
   std::string input = (file.is_open() ? std::string{std::istreambuf_iterator<char>{file}, {}} : argv[1]);
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
