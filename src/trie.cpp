#include "trie.h"


namespace std {

Trie::Trie() {
  root_ = new_trie();
}

Trie::~Trie() {}

trie_element_t* Trie::new_trie() {
  trie_element_t *new_trie = new trie_element_t;
  new_trie->leaf_node = false;
  new_trie->val = 0;

  for(int i = 0; i < CHILD_SIZE; i++) {
    new_trie->children[i] = NULL;
  }
  return new_trie;
}

void Trie::add_string(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  for(int i = 0; i < len; i++){
    int index = ascii_to_index(str[i]);
    if(curr_trie->children[index] == NULL) {
      trie_element_t *next_trie = new_trie();
      curr_trie->children[index] = next_trie;
    }
    curr_trie = curr_trie->children[index];
    curr_trie->val = str[i];
  }
  curr_trie->leaf_node = true;
}

bool Trie::lookup(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  for(int i = 0; i < len; i++){
    int index = ascii_to_index(str[i]);
    if(curr_trie->children[index] == NULL) {
      return false;
    }
    curr_trie = curr_trie->children[index];
  }
  return true;
}

bool Trie::remove_str(string str) {
  int len = str.length();
  trie_element_t *curr_trie = root_;
  trie_element_t *first_dead_branch = root_;
  for(int i = 0; i < len; i++){
    int index = ascii_to_index(str[i]);

    for(int i = 0; i < CHILD_SIZE; i++) {
      if((i != index) & (curr_trie->children[i] != NULL)) {
        first_dead_branch = curr_trie->children[index];
      }
    }
    if (curr_trie->leaf_node == true) {
      first_dead_branch = curr_trie->children[index];
    }
    curr_trie = curr_trie->children[index];
  }
  trie_element_t *iter_trie = first_dead_branch;

  while(iter_trie != first_dead_branch) {
    delete 
  }
  return true;
}

int Trie::ascii_to_index(char c) {
  return c - 97;
}


} // namespace std