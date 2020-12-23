#include "trie.h"


namespace std {

Trie::Trie() {
  root_ = new_trie();
}

Trie::~Trie() {
  for(int i = 0; i < CHILD_SIZE; i++) {
    if(root_->children[i] != NULL) {
      delete root_->children[i];
    }
  }
  delete root_;
}

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
    if(curr_trie->children[str[i]] == NULL) {
      trie_element_t *next_trie = new_trie();
      curr_trie->children[str[i]] = next_trie;
    }
    curr_trie->val = str[i];
    curr_trie = curr_trie->children[str[i]];
  }
  curr_trie->leaf_node = true;
}

} // namespace std