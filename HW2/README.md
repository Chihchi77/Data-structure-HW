# HW2 – Linked List Implementation

## 作業說明
本作業實作兩種 linked list：  
1. **SingleList (單向鏈結串列)**  
2. **XORList (XOR linked list)**  

並透過 driver code 比較兩者在大量隨機插入、刪除、走訪與反轉操作時的效能。

---

## 專案結構
```
.
├── 113511013_hw2.cpp     # 主程式，包含 SingleList / XORList 與 driver code
├── 113511013_hw2.h       # 標頭檔，定義 Node / Nodex 結構與 class
├── Makefile              # 編譯腳本
├── slist_test_output1.txt  # SingleList 走訪輸出（reverse前）
├── slist_test_output2.txt  # SingleList 走訪輸出（reverse後）
├── xlist_test_output1.txt  # XORList 走訪輸出（reverse前）
├── xlist_test_output2.txt  # XORList 走訪輸出（reverse後）
└── README.md             # 說明文件
```

---

## 編譯與執行

### 編譯
```bash
make
```
會產生可執行檔 `hw2`。

### 執行
```bash
make run
```
會執行 driver code，並輸出測試結果與 txt 檔案。

### 清理
```bash
make clean
```
刪除執行檔。

---

## 功能說明

### SingleList
- `list_prepend(int k)`：在串列頭插入新節點。 
- `list_insert(Node* x, Node* y)`:在y這個節點後加x節點。
- `list_delete(Node* n)`：刪除節點並釋放記憶體。  
- `list_ins_del(int k)`：若值存在則刪除，不存在則插入。  
- `list_reverse()`：反轉整個串列。  
- `list_walk(ofstream&, string&)`：輸出串列內容到檔案。  

### XORList
- `list_prepend(int k)`：在串列頭插入新節點（利用 XOR(prev, next)）。  
- `list_insert(Nodex* x, Nodex* y)`:在y這個節點後加x節點。
- `list_delete(Nodex* n)`：刪除節點並釋放記憶體。  
- `list_ins_del(int k)`：若值存在則刪除，不存在則插入。  
- `list_reverse()`：反轉整個串列。  
- `list_walk(ofstream&, string&)`：輸出串列內容到檔案。  

---

## Driver Code 測試流程
在 `main()` 中會依序呼叫：  

1. **SingleList 測試**  
   - 插入 `2 × 10^5` 筆隨機數  
   - 再進行 `2 × 10^5` 次隨機插入/刪除  
   - 呼叫 `list_walk()` 輸出結果  
   - 反轉串列並再次輸出  
   - 使用 `std::chrono::high_resolution_clock` 量測耗時  

2. **XORList 測試**  
   - 流程與 SingleList 相同  

---

## 範例輸出 (終端機)
```
Testing SingleList......
SingleList time: 105091 ms
Testing XORList......
XORList time: 255843 ms
```

---

## 時間複雜度分析

| Operation   | SingleList | XORList |
|-------------|------------|---------|
| Insert Head | O(1)       | O(1)    |
| Insert After Node | O(1) | O(1)    |
| Search      | O(n)       | O(n)    |
| Delete      | O(n)       | O(n)    |
| Reverse     | O(n)       | O(n)    |
| Walk        | O(n)       | O(n)    |

---

## Author
- 學號：113511013  
- 課程：Data Structure 
- 說明：此程式碼實作Single linked list 與 XOR linked list，並透過 driver code 驗證正確性與比較效能。
