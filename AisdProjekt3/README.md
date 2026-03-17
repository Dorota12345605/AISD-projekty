# 🌲 Dynamic Sparse Table (Trie-Based)

This project implements a **dynamic sparse table** using a **trie structure** as an alternative to hash tables, providing better worst-case performance.

---

## 📖 Description

To store values indexed by sparse keys from a universe `N`, hash tables are commonly used. However, they may perform poorly in the worst case.

This implementation uses a **trie**, which guarantees more predictable access time.

The trie is defined by two parameters:
- `n` – number of children of the root  
- `k` – number of children for each subsequent node  

Each node stores **at most one key**.

---

## ⚙️ Operations

### ➕ Insert (`I x`)
- Start from the root  
- If empty → insert `x`  
- Otherwise:
  - Traverse using:
    - `x mod n`
    - then repeated `mod k`
  - Insert at the first free node  
- If key exists:
  ```
  x exist
  ```

---

### 🔍 Lookup (`L x`)
- Traverse using `mod n` and `mod k`  
- If found:
  ```
  x exist
  ```
- Otherwise:
  ```
  x not exist
  ```

---

### ❌ Delete (`D x`)
- Find node `p` containing `x`  
- If not found:
  ```
  x not exist
  ```
- If found:
  - If `p` is a leaf → delete it  
  - Otherwise:
    - Find the **leftmost leaf node `q`**  
    - Copy value from `q` to `p`  
    - Delete node `q`  

---

### 📖 Print (`P`)
- Print keys using **preorder traversal**

---

## 📥 Input

```
<number_of_operations>
<min> <max>
<n> <k>

<commands>
```

### Commands:
- `I x` – insert  
- `L x` – lookup  
- `D x` – delete  
- `P` – print  

---

## 📤 Output

- Print results only when required  
- No output for successful insert/delete  

---

## 📊 Example

### Input
```
29
0 511
8 4

I 3
I 31
I 150
I 190
I 130
I 174
I 81
I 30
I 203
P
L 32
L 30
L 150
D 150
L 150
I 150
L 150
D 3
L 3
I 3
L 3
D 3
L 3
D 30
L 30
I 30
L 30
D 30
L 30
```

### Output
```
3 81 130 203 150 174 190 30 31
32 not exist
30 exist
150 exist
150 not exist
150 exist
3 not exist
3 exist
3 not exist
30 not exist
30 exist
30 not exist
```
