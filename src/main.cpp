#include "trie.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_usage() {
  std::cerr << "Usage: "
            << " <option(s)>\n"
            << "Options:\n"
            << "\th\t\tShow this help message\n"
            << "\ti <string>\tinsert\n"
            << "\tl <string>\tlookup\n"
            << "\tr <string>\tremove string\n"
            << std::endl;
}

int main() {

  Trie *trie_instance = new Trie();

  while (1) {
    std::cout << "> ";
    std::string command_line_text;
    std::getline(std::cin, command_line_text);

    // Quit
    if (command_line_text == "q") {
      delete trie_instance;
      return 0;
    }

    // Instructions are one character in length
    char instruction = command_line_text[0];

    // If the instruction is > 1 in length, we print usage
    if (command_line_text[1] != ' ' && command_line_text.length() != 1) {
      print_usage();
    }
    // Normal Execution
    else {
      // Remove instruction and space from string
      command_line_text.erase(0, 2);

      switch (instruction) {
      case 'a':
      case 'i':
        trie_instance->add_string(command_line_text);
        break;
      case 'l':
        if (trie_instance->lookup(command_line_text)) {
          std::cout << "lookup - " << command_line_text << ": TRUE\n";
        } else {
          std::cout << "lookup - " << command_line_text << ": FALSE\n";
        }
        break;
      case 'r':
        trie_instance->remove_str(command_line_text);
        break;
      case 'h':
        print_usage();
        break;
      default:
        print_usage();
        break;
      }
    }
  }

  delete trie_instance;
  return 0;
}