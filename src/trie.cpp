#include "trie.h"

namespace std {

Trie::Trie() { root_ = new_trie(); }

Trie::~Trie() {}

trie_element_t *Trie::new_trie() {
  trie_element_t *new_trie = new trie_element_t;
  new_trie->leaf_node = false;
  new_trie->val = 0;

  for (int i = 0; i < CHILD_SIZE; i++) {
    new_trie->children[i] = NULL;
  }
  return new_trie;
}

void Trie::add_string(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  for (int i = 0; i < len; i++) {
    int index = ASCII_TO_INDEX(str[i]);
    if (curr_trie->children[index] == NULL) {
      trie_element_t *next_trie = new_trie();
      curr_trie->children[index] = next_trie;
    }
    curr_trie = curr_trie->children[index];
    curr_trie->val = str[i];
  }
  curr_trie->leaf_node = true;
}

bool Trie::remove_str(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  for (int i = 0; i < len; i++) {
    int index = ASCII_TO_INDEX(str[i]);
    curr_trie = curr_trie->children[index];
  }

  if (!is_deadend(curr_trie) || 1) {
    curr_trie->leaf_node = false;
    return true;
  }

  return false;
}

bool Trie::lookup(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  for (int i = 0; i < len; i++) {
    int index = ASCII_TO_INDEX(str[i]);
    if (curr_trie->children[index] == NULL) {
      return false;
    }
    curr_trie = curr_trie->children[index];
  }
  return curr_trie->leaf_node;
}

bool Trie::is_deadend(trie_element_t *trie) {
  for (int i = 0; i < CHILD_SIZE; i++) {
    if (trie->children[i] != NULL) {
      return false;
    }
  }
  return true;
}


} // namespace std