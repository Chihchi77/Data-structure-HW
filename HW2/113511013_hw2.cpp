#include "113511013_hw2.h"
#include <list>
#include <struct>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//singlelist
SList::SList(){}
Slist::SList(Node* h): head = h{}
SList::~SList(){}
ofstream& SList::list_walk(ofstream& fout, string& filename){
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
void SList::list_insert(int k){
  head->next = head;
  head->data = k;
  return;
}
bool SList::list_search(int k){
  Node* curr = head;

  while (curr != nullptr){
    if ((curr->data) == k)
      return true;
    else curr = curr->next;
  }

  if (curr == nullptr) return false;
}
void SList::ist_delete(Node* n){
  Node* curr = head;

  while(curr != nullptr){
    if (curr->next == n)
      curr->next = n->next;
    curr = curr->next;
  }

  return;
}
int SList::list_ins_del(int k){
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
void SList::list_reverse(){
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