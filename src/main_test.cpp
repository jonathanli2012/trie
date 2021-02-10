#include "trie.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

int main() {
  std::string file = "words.txt";
  std::string curr_word;

  ifstream open_file(file);
  Trie *trie_instance = new Trie();

  cout << "--------------------\ninserting\n--------------------\n";

  while (std::getline(open_file, curr_word)) {
    trie_instance->add_string(curr_word);
  }

  cout << "--------------------\nremoving\n--------------------\n";

  int index = 0;
  index++;

  open_file.clear();
  open_file.seekg(0);

  while (std::getline(open_file, curr_word)) {
    if(index & 1UL) {
      cout << curr_word << "\n";
      trie_instance->remove_str(curr_word);
    }
    index++;
  }
  
  cout << "--------------------\n" << "complete inserting " << index << " elements\n" << "--------------------\n";

  while (std::getline(open_file, curr_word)) {
    if(index & 1UL) {
      trie_instance->remove_str(curr_word);
    }
    index++;
  }

  return 0;
}