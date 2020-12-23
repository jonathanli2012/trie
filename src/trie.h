#include <stdint.h>
#include <stdlib.h>
#include <string>

#define CHILD_SIZE 200

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

  void add_string(string str);

protected:
  trie_element_t *root_;
};
} // namespace std