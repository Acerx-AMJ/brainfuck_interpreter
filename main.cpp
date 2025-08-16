#include "brainfuck.hpp"
#include <fstream>

inline void read_file(std::string& string) {
   std::ifstream file (string);
   if (!file) {
      return;
   }

   string.clear();
   std::string temp;
   while (std::getline(file, temp)) {
      string += temp + '\n';
   }
}

int main(int argc, char* argv[]){
   if (argc != 2) {
      std::cerr << "Expected two args, got " << argc << " instead.\n";
      return -1;
   }
   std::string arg = argv[1];
   read_file(arg);

   run_brainfuck(arg);
   return 0;
}
