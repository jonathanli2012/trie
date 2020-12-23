#include <stdint.h>
#include <stdlib.h>
#include <string>

#define CHILD_SIZE 26

namespace std {

typedef struct trie_element trie_element_t;

struct trie_element { 
    char val;
    bool leaf_node;
    trie_element_t *children[CHILD_SIZE];
};


class Trie {

public:

  Trie();

  /**
   * @brief Destructor for Trie type
   *
   * frees dynamically allocated memory for Trie
   */
  ~Trie();

  trie_element_t* new_trie();

  bool lookup(string str);

  bool remove_str(string str);

  void add_string(string str);

  int ascii_to_index(char c);

protected:
  trie_element_t *root_;
};
} // namespace std