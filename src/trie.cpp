#include "trie.h"
#include <iostream>

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

bool Trie::has_single_child(trie_element_t *elem, char c) {
  int index = ASCII_TO_INDEX(c);
  for (int i = 0; i < CHILD_SIZE; i++) {
    if ((elem->children[i] != NULL) && (i != index)) {
      return false;
    }
  }
  return true;
}

bool Trie::remove_str_mem(string str) {

  int len = str.length();
  int first_free_node = 0;

  trie_element_t *traversal[len];
  trie_element_t *curr_trie = root_;
  trie_element_t *prev_trie = root_;

  for (int i = 0; i < len - 1; i++) {
    int index = ASCII_TO_INDEX(str[i]);
    prev_trie = curr_trie;
    curr_trie = curr_trie->children[index];

    if (has_single_child(curr_trie, str[i+1])) {
      traversal[i] = prev_trie;
    } else {
      first_free_node = i + 1;
    }
  }
  traversal[len - 1] = curr_trie->children[ASCII_TO_INDEX(str[len - 1])];

  // remove children
  for (int i = len - 1; i >= first_free_node; i--) {
    //std::cout << i << "\n";
    int index = ASCII_TO_INDEX(str[i]);
    std::cout << traversal[i]->children[index]->val << "\n";
    delete traversal[i]->children[index];
  }
  return true;
}

bool Trie::remove_str(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  trie_element_t *first_free_trie = root_;
  for (int i = 0; i < len; i++) {
    int index = ASCII_TO_INDEX(str[i]);
    curr_trie = curr_trie->children[index];
  }

  if (!is_deadend(curr_trie)) {
    curr_trie->leaf_node = false;
    return true;
  }

  remove_str_mem(str);
  return true;
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