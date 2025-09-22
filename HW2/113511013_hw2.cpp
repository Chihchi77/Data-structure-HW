#include "113511013_hw2.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <chrono>
#include <random>
using namespace std;

//singlelist
SingleList::SingleList(): head(nullptr){}
SingleList::SingleList(Node* h): head(h){}
SingleList::~SingleList(){
  Node* curr = head;
  while (curr != nullptr){
    Node* next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
}
ofstream& SingleList::list_walk(ofstream& fout, string& filename){
  fout.open(filename);

  if (!fout.is_open()){
    cerr << "Who is " << filename << "??" << endl;
    return fout;
  }
  fout << "List: ";
  Node* curr = head;
  while (curr != nullptr){
    if (curr->next != nullptr)
      fout << curr->data << ", ";
    else fout << curr->data << endl;
    curr = curr->next;
  }
  
  return fout;
}
void SingleList::list_insert(int k){
  Node* newnode = new Node();
  newnode->data = k;
  newnode->next = head;
  head = newnode;
  cout << "Inserted " << k << endl;
  return;
}
bool SingleList::list_search(int k){
  Node* curr = head;

  while (curr != nullptr){
    if ((curr->data) == k)
      cout << "Found " << k << endl;
      return true;
    curr = curr->next;
  }
  cout << "Not Found " << k << endl;
  return false;
}
void SingleList::list_delete(Node* n){
  Node* curr = head;

  if (curr == n){
    head = head->next;
    delete curr;
    cout << "Deleted " << k << endl;
    return;
  }

  while(curr != nullptr){
    if (curr->next == n){
      Node* target = curr->next;
      curr->next = target->next;
      delete target;
      cout << "Deleted " << k << endl;
      return;
    }
    curr = curr->next;
  }
  cout << "Deleted " << k << endl;
  return;
}
int SingleList::list_ins_del(int k){
  Node* curr = head;
  
  if (head == nullptr){
    Node* newnode = new Node();
    newnode->data = k;
    newnode->next = nullptr;
    head = newnode;
    cout << "Inserted " << k << endl;
    return 0;
  }

  //insert->return 0; delete-> return 1;
  while(curr != nullptr){
    if (curr->next != nullptr && curr->next->data == k) {
      Node* target = curr->next;
      curr->next = target->next;
      delete target;
      cout << "Deleted " << k << endl;
      return 1;
    }

    curr = curr->next;
  }
  if (curr == nullptr){
    Node* newnode = new Node();
    newnode->data = k;
    newnode->next = head;
    head = newnode;
    cout << "Inserted " << k << endl;
    return 0;
  }
}
void SingleList::list_reverse(){
  Node* curr = head;
  Node* prev = nullptr;

  while (curr != nullptr){
    Node* nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
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
XORList::~XORList(){
  Nodex* curr = head;
  Nodex* prev = nullptr;

  while (curr != nullptr){
    Nodex* next = XOR(prev, curr->npx);
    prev = curr;
    delete curr;
    curr = next;
  }
  
  head = nullptr;
}
ofstream& XORList::list_walk(ofstream& fout, string& filename){
  fout.open(filename);
  if (!fout.is_open()){
    cerr << "Who is " << filename << "??" << endl;
    return fout;
  }
  fout << "List: ";
  Nodex* prev = nullptr;
  Nodex* curr = head;
  while (curr != nullptr){
    Nodex* next = XOR(prev, curr->npx);
    if (next != nullptr)
      fout << curr->data << ", ";
    else
      fout << curr->data << endl;
    prev = curr;
    curr = next;
  }

  return fout;
}
void XORList::list_insert(int k){
  Nodex* newnode = new Nodex();
  newnode->data = k;
  newnode->npx = XOR(nullptr, head);
  
  if (head != nullptr){
    Nodex* next = XOR(nullptr, head->npx);
    head->npx = XOR(newnode, next);
  }
  head = newnode;
  cout << "Inserted " << k << endl;
  return;
}
bool XORList::list_search(int k){
  Nodex* curr = head;
  Nodex* prev = nullptr;

  while(curr != nullptr){
    if (curr->data == k)
      cout << "Found " << k << endl;
      return true;
    Nodex* next = XOR(prev, curr->npx);
    prev = curr;
    curr = next;
  }

  if (curr == nullptr){
    cout << "Not Found " << k << endl;
    return false;
  }
}
void XORList::list_delete(Nodex* n){
  Nodex* curr = head;
  Nodex* prev = nullptr;
  while (curr != nullptr && curr != n){
    Nodex* next = XOR(prev, curr->npx);
    prev = curr;
    curr = next;
  }
  //沒找到n
  if (curr == nullptr){
    cerr << "??" << endl;
    return;
  }

  Nodex* next = XOR(prev, curr->npx);

  // 更新 prev 的 npx
  if (prev != nullptr) {
    prev->npx = XOR(XOR(prev->npx, curr), next);
  } else {
  // 如果刪掉的是頭節點
    head = next;
  }

  // 更新 next 的 npx
  if (next != nullptr) {
    next->npx = XOR(XOR(next->npx, curr), prev);
  }
  delete curr;
  cout << "Deleted " << n->data << endl;
  return;
}
int XORList::list_ins_del(int k){
  Nodex* curr = head;
  Nodex* prev = nullptr;

  while(curr != nullptr){
    Nodex* next = XOR(prev, curr->npx);
    if (curr->data == k){
      // 更新 prev 的 npx
      if (prev != nullptr) {
        prev->npx = XOR(XOR(prev->npx, curr), next);
      } else {
      // 如果刪掉的是頭節點
        head = next;
      }
      // 更新 next 的 npx
      if (next != nullptr) {
        next->npx = XOR(XOR(next->npx, curr), prev);
      }
      delete curr;
      cout << "Deleted " << k << endl;
      return 1;
    }
    prev = curr;
    curr = next;
  }

  if (curr == nullptr){
    Nodex* newnode = new Nodex();
    newnode->data = k;
    newnode->npx = XOR(nullptr, head);
  
    if (head != nullptr){
      Nodex* next = XOR(nullptr, head->npx);
      head->npx = XOR(newnode, next);
    }
    head = newnode;
    cout << "Inserted " << k << endl;
    return 0;
  }
}
void XORList::list_reverse(){
  Nodex* curr = head;
  Nodex* prev = nullptr;
  while (curr != nullptr){
    Nodex* next = XOR(prev, curr->npx);
    prev = curr;
    curr = next;
  }
  head = prev;
  return;
}

//driver code
void slist_test(){
  cout << "Testing SingleList......" << endl;
  SingleList list;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; i < 200000; i++){
    int val = rand() % 1000000 + 1;
    list.list_insert(val);
  }

  for (int i = 0; i < 200000; i++){
    int val = rand() % 1000000 + 1;
    list.list_ins_del(val);
  }

  ofstream fout;
  string f1 = "slist_test_output1.txt";
  list.list_walk(fout, f1);
  fout.close();

  list.list_reverse();
  string f2 = "slist_test_output2.txt";
  list.list_walk(fout, f2);
  fout.close();
  
  auto end = chrono::high_resolution_clock::now();
  cout << "SingleList time: "
       << chrono::duration_cast<chrono::milliseconds>(end - start).count()
       << " ms" << endl;
  return;
}

void xlist_test(){
  cout << "Testing XORList......" << endl;
  XORList list;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; i < 200000; i++){
    int val = rand() % 1000000 + 1;
    list.list_insert(val);
  }

  for (int i = 0; i < 200000; i++){
    int val = rand() % 1000000 + 1;
    list.list_ins_del(val);
  }

  ofstream fout;
  string f1 = "xlist_test_output1.txt";
  list.list_walk(fout, f1);
  fout.close();

  list.list_reverse();
  string f2 = "xlist_test_output2.txt";
  list.list_walk(fout, f2);
  fout.close();
  
  auto end = chrono::high_resolution_clock::now();
  cout << "XORList time: "
       << chrono::duration_cast<chrono::milliseconds>(end - start).count()
       << " ms" << endl;
  return;
}

int main(){
  srand(time(0));
  slist_test();
  xlist_test();
  return 0;
}