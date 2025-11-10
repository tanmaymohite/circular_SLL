# 🔁 Circular Singly Linked List (CSLL) in C

A **menu-driven C program** to perform various operations on a **Circular Singly Linked List (CSLL)** including creation, insertion, deletion, counting, and display.  
This project demonstrates core **Data Structures** concepts and **dynamic memory management** using pointers.

---

## 📋 Features

✅ Create a Circular Singly Linked List (CSLL)  
✅ Display all elements in the list  
✅ Insert nodes:
- At the beginning
- At the end
- Between specific positions  

✅ Delete nodes:
- From the beginning
- From the end
- From a specific position  

✅ Count total number of nodes  

✅ Menu-driven interface for easy testing  

---

## 🧠 Concepts Used

- Dynamic Memory Allocation (`malloc`)  
- Structures in C (`typedef struct`)  
- Pointers and Linked List traversal  
- Circular linking (`last->next = head`)  
- Modular programming using multiple functions  

---

## 🧩 Functions Overview

| Function | Description |
|-----------|-------------|
| `createCLL()` | Creates a circular singly linked list |
| `displayCSLL()` | Displays all nodes in the list |
| `insertfirst()` | Inserts a node at the beginning |
| `insertLast()` | Inserts a node at the end |
| `insertBetween()` | Inserts a node at a given position |
| `deletefirst()` | Deletes the first node |
| `deleteLast()` | Deletes the last node |
| `deleteBetween()` | Deletes a node from a given position |
| `countNodes()` | Returns total number of nodes |

---

## 🧰 How to Run

### 🖥️ On Windows
1. Open **Turbo C**, **Code::Blocks**, or **Dev C++**.
2. Copy and paste the code from `circular_linked_list.c`.
3. Compile and run the program.

### 💻 Using GCC (Command Line)
```bash
gcc circular_linked_list.c -o csll
./csll
