#ifndef _TRIE_H
#define _TRIE_H

#include "nodeTrie.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stack>

class trie {
private:
  nodeTrie *root;
  void dfsHelper(nodeTrie *current, std::string str);
  void destructorHelper(nodeTrie *current);
public:
  trie();
  ~trie();
  void insert(std::string word);
  bool search(std::string word);
  void dfs();
};

trie::trie() { root = new nodeTrie(); }

trie::~trie() {
  // to-do
  // Implementa un recorrido del trie para
  // liberar su memoria
  destructorHelper(root);
}

void trie::destructorHelper(nodeTrie *current) {
  for (int i=0; i<26; i++) {
    if (current->getChild(char('a' + i)) != nullptr) {
      destructorHelper(current->getChild(char('a' + i)));
    }
  }
}

void trie::insert(std::string word) {
  nodeTrie *current = root;
  for (int i = 0; i < (int)word.length(); i++) {
    if (current->getChild(word[i]) == nullptr) {
      nodeTrie *newNode = new nodeTrie(word[i], current);
      current->setChild(newNode);
    }
    current = current->getChild(word[i]);
  }
  current->setIsLeaf(true);
}

bool trie::search(std::string word) {
  nodeTrie *current = root;
  if (current == nullptr)
    return false;
  for (int i = 0; i < (int)word.length(); i++) {
    current = current->getChild(word[i]);
    if (current == nullptr)
      return false;
  }
  return current->getIsLeaf();
}

void trie::dfs() {
  // to-do
  // Implementa un recorrido DFS del trie
  // para imprimir todas las palabras en orden alfabetico
  nodeTrie *current = root;
  if (current == nullptr) {
    std::cout << "" << std::endl;
  } else {
    dfsHelper(current, "");
  }
}

void trie::dfsHelper(nodeTrie *current, std::string str) {
  if (current->getIsLeaf()) {
    std::cout << str << std::endl;
  }
  for (int i=0; i<26; i++) {
    if (current->getChild(char('a' + i)) != nullptr) {
      std::string newStr = str + char('a' + i);
      dfsHelper(current->getChild(char('a' + i)), newStr);
    }
  }
}

#endif // _TRIE_H