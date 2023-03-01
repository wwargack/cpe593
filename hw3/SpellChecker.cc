//Walter Wargacki
//Sources:
//Read file in from https://stackoverflow.com/questions/20372661/read-word-by-word-from-file-in-c
#include <iostream>
#include <fstream>
using namespace std;

class Trie {
private:
  class Node {
  public:
    bool isWord;
    Node* bin[26];
  };
  Node* root;

public:
  Trie() { root = new Node(); }
  ~Trie() { delete[] root; }
  Trie(const Trie& orig);
  Trie& operator =(const Trie& orig);

  void insert(string word) {
    Node* p = root;
    for (int i = 0; i < word.length(); i++) {
      char c = word[i] - 'a';
      if (p->bin[c] == nullptr)
        p->bin[c] = new Node();
      p = p->bin[c];
    }
    p->isWord = true;
  }

  bool contains(string word) {
    Node* p = root;
    for (int i = 0; i < word.length(); i++) {
      char c = word[i] - 'a';
      if (p->bin[c] == nullptr)
        break;
      p = p->bin[c];
    }
    if (p->isWord)
      return true;
    return false;
  }
};


int main() {
  Trie trie;

  string word;

  ifstream en213k;
  en213k.open("./data/en213k.txt");
  while (en213k >> word) {
    trie.insert(word);
  }
  en213k.close();

  ifstream triespellcheck;
  bool temp;
  triespellcheck.open("./words.txt");
  while (triespellcheck >> word) {
    if (trie.contains(word))
      cout << word << ": True\n";
    else
      cout << word << ": False\n";
  }
  triespellcheck.close();

};