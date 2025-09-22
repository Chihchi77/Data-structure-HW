#include <fstream>
using namespace std;

//node for singlelist
struct Node{
  int data;
  Node* next;
};

//node for xorlist
struct Nodex{
  int data;
  Nodex* npx;
};

class SingleList{
private:
  Node* head;
public:
  SingleList();
  SingleList(Node* h);
  ~SingleList();
  ofstream& list_walk(ofstream& fout, string& filename);
  void list_prepend(int k);//insert k to the head of slist
  void list_insert(Node* x, Node* y);
  bool list_search(int k);
  void list_delete(Node* n);
  int list_ins_del(int k);
  void list_reverse();
};

  class XORList{
  private:
    Nodex* head;
  public:
    XORList();
    XORList(Nodex* h);
    ~XORList();
    ofstream& list_walk(ofstream& fout, string& filename);
    void list_prepend(int k);//insert k to the head of slist
    void list_insert(Nodex* x, Nodex* y);
    bool list_search(int k);
    void list_delete(Nodex* n);
    int list_ins_del(int k);
    void list_reverse();
  };