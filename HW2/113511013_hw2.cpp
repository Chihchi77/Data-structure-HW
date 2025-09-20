#include "113511013_hw2.h"
#include <struct>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
using namespace std;

//singlelist
SingleList::SingleList(): head(nullptr){}
SingleList::SingleList(Node* h): head = h{}
SingleList::~SingleList(): head(nullptr){}
ofstream& SingleList::list_walk(ofstream& fout, string& filename){
  fout.open(filename);

  if (!fout.is_open()){
    cerr << "Who is " << filename << "??" << endl;
    return fout;
  }

  Node* curr = head;
  while (curr != nullptr){
    if (curr->next != nullptr)
      fout << curr << ", ";
    else fout << curr << endl;
    curr = curr->next;
  }

  return fout;
}
void SingleList::list_insert(int k){
  head->next = head;
  head->data = k;
  return;
}
bool SingleList::list_search(int k){
  Node* curr = head;

  while (curr != nullptr){
    if ((curr->data) == k)
      return true;
    else curr = curr->next;
  }

  if (curr == nullptr) return false;
}
void SingleList::ist_delete(Node* n){
  Node* curr = head;

  if (curr == n){
    curr = curr->next;
    return;
  }

  while(curr != nullptr){
    if (curr->next == n)
      curr->next = n->next;
    curr = curr->next;
  }

  return;
}
int SingleList::list_ins_del(int k){
  Node* curr = head;
  Node* curr_nxt = curr->next;
  SList S(head);

  //insert->return 0; delete-> return 1;
  while(curr != nullptr){
    if (curr_nxt->data == k){
      curr->next = curr_nxt->next;
      return 1;
    }
    curr = curr->next;
  }
  if (curr == nullptr){
    head->next = head;
    head->data = k;
    return 0;
  }
}
void SingleList::list_reverse(){
  Node* curr = head;
  Node* prev = nullptr;
  Node* nxt = curr->next;

  while (curr != nullptr){
    curr->next = prev;
    prev = curr;
    curr = nxt;
    nxt = curr->next;
  }

  head = prev;

  return;
}

//XORList
Nodex* XOR(Nodex* a, Nodex* b){
  return (Nodex*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

XORList::XORList(): head(nullptr){}
XORList::XORList(Nodex* h): head(h){}
XORList::~XORList(): head(nullptr){}
ofstream& XORList::list_walk(ofstream& fout, string& filename){
  fout.open(filename);
  if (!fout.is_open()){
    cerr << "Who is " << filename << "??" << endl;
    return fout;
  }

  Nodex* prev = nullptr;
  Nodex* curr = head;
  while (curr != nullptr){
    if (XOR(prev, curr->npx) != nullptr)
      fout << curr->data << ", ";
    else fout << curr->data << endl;
    prev = curr;
    curr = XOR(prev, curr->npx);
  }
  return fout;
}
void XORList::list_insert(int k){
  Nodex* newnode;
  newnode->data = k;
  newnode->npx = XOR(nullptr, head);
  
  if (head != nullptr){
    Nodex* next = XOR(nullptr, head->npx);
    head->npx = XOR(newnode, next);
  }
  head = newnode;
  return;
}
bool XORList::list_search(int k){
  Nodex* curr = head;
  Nodex* prev = nullptr;

  while(curr != nullptr){
    if (curr->data == k)
      return true;
    Nodex* next = XOR(prev, curr->npx);
    prev = curr;
    curr = next;
  }

  if (curr == nullptr)
    return false;
}
void XORList::list_delete(Nodex* n){
  Nodex* curr = head;
  while (curr != nullptr){
    if (curr == n){
      
    }
  }
}
int XORList::list_ins_del(int k);
void XORList::list_reverse();