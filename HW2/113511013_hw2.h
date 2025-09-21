#include <fstream>
using namespace std;

//node for singlelist
struct Node{
  int data;
  Node* next;
}

//node for xorlist
struct Nodex{
  int data;
  Nodex* npx;
}

class SingleList(){
private:
  Node* head;
public:
  SingleList();
  SingleList(Node* h);
  ~SingleList();
  ofstream& list_walk(ofstream& fout, string& filename);
  void list_insert(int k);//insert k to the head of slist
  bool list_search(int k);
  void list_delete(Node* n);
  int list_ins_del(int k);
  void list_reverse();
}

  class XORList(){
  private:
    Nodex* head;
  public:
    XORList();
    XORList(Nodex* h);
    ~XORList();
    ofstream& list_walk(ofstream& fout, string& filename);
    void list_insert(int k);//insert k to the head of slist
    bool list_search(int k);
    void list_delete(Nodex* n);
    int list_ins_del(int k);
    void list_reverse();
  }