#include <stdint.h>
#include <stdlib.h>
#include <string>

#define CHILD_SIZE 26

#define ASCII_TO_INDEX(x) ((x)-97)

namespace std {

typedef struct trie_element trie_element_t;

struct trie_element {
  char val;
  bool end_node;
  int children_count;
  trie_element_t *children[CHILD_SIZE];
};

class Trie {

public:
  /**
   * @brief Constructor for Trie type
   *
   * dynamically allocates memory for Trie
   */
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

  bool has_single_child(trie_element_t *elem, char c);

  bool remove_str_mem(string str);



protected:
  trie_element_t *root_;
};
} // namespace std