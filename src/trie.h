#include <stdint.h>
#include <stdlib.h>
#include <string>

#define CHILD_SIZE 26

#define ASCII_TO_INDEX(x) ((x)-97)

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

  trie_element_t *new_trie();

  void add_string(string str);

  bool remove_str(string str);

  bool lookup(string str);

  bool is_deadend(trie_element_t *trie);

protected:
  trie_element_t *root_;
};
} // namespace std