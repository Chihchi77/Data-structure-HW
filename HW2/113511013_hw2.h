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
  SList(list L);
  ~SList();
  ofstream& list_walk(ofstream& fout, string& filename);
  void list_insert(int k);
  bool list_search(int k);
  void list_delete(Node* n);
  int list_ins_del(int k);
  void list_reverse();
