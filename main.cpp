#include "brainfuck.hpp"
#include <fstream>

int main(int argc, char* argv[]){
   if (argc != 2) {
      std::cerr << "Expected two args, got " << argc << " instead.\n";
      return -1;
   }
   std::string arg = argv[1];
   std::ifstream file (arg);

   if (file.is_open()) {
      arg.clear();
      std::string temp;

      while (std::getline(file, temp)) {
         arg += temp + '\n';
      }      
   }
   run_brainfuck(arg);
   return 0;
}
