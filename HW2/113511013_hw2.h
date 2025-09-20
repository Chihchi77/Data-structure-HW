#include <fstream>
#include <list>
using namespace std;

class SList(){
private:
  list<int> slist;
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
}