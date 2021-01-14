#include "trie.h"
#include <iostream>
#include <list>

namespace std {

Trie::Trie() { root_ = new_trie(); }

Trie::~Trie() {}

trie_element_t *Trie::new_trie() {
  trie_element_t *new_trie = new trie_element_t;
  new_trie->end_node = false;
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
  curr_trie->end_node = true;
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

  std::list<trie_element_t *> elems = {};

  trie_element_t *curr_trie = root_;
  trie_element_t *prev_trie = root_;
  trie_element_t *first_node = root_;

  for (int i = 0; i < len; i++) {
    int index = ASCII_TO_INDEX(str[i]);
    prev_trie = curr_trie;
    curr_trie = curr_trie->children[index];
    if(curr_trie->children_count <= 1) {
      if(elems.size() == 0) {
        first_node = prev_trie;
      }
      elems.push_front(curr_trie);
    }
    else {
      elems.clear();
    }
  }

  while(!elems.empty()) {
    trie_element_t * tmp = elems.front();
    delete(tmp);
    elems.pop_front();
  }

  first_node->children_count = 0;
  for(int i = 0; i < CHILD_SIZE; i++) {
    first_node->children[i] = nullptr;
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
    curr_trie->end_node = false;
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
  return curr_trie->end_node;
}

bool Trie::is_deadend(trie_element_t *trie) {
  return (trie->children_count == 0);
}

} // namespace std