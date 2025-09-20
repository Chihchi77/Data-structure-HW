#include <fstream>
#include <struct>
using namespace std;

struct Node{
  int data;
  Node* next;
}

class SList(){
private:
  Node* head;
public:
  SList();
  SList(Node* h);
  ~SList();
  ofstream& list_walk(ofstream& fout, string& filename);
  void list_insert(int k);//insert k to the head of slist
  bool list_search(int k);
  void list_delete(Node* n);
  int list_ins_del(int k);
  void list_reverse();
