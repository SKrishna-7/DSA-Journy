# 🎨 Pattern Printing in C++

This folder contains my **C++ pattern printing practice programs**,  
which helped me strengthen my understanding of **nested loops, logic formulation, and space-star relations**.  

Every pattern here is a small logical puzzle — and solving them built my foundation for problem-solving in DSA.

---

## 🧠 What I Learned by Doing This

By writing and analyzing these pattern programs, I learned:
- 🧩 How **nested loops** work and how inner and outer loops interact.
- 🔢 How to calculate **space and star formulas** (`n - i`, `2 * i - 1`, etc.)
- ✨ The importance of **loop dry runs** for debugging logic.
- ⚙️ How to think in terms of **rows** and **columns** like a matrix.
- 💪 The power of **mathematical patterns** behind shapes.

---



## 🧩 Patterns Overview

| File Name | Pattern Type | Description | Formula |
|------------|---------------|--------------|-----------|
| `pattern1_square.cpp` | Square | Solid block of `*` | `i ≤ n`, `j ≤ n` |
| `pattern2_right_triangle.cpp` | Right Triangle | Increasing stars | `j ≤ i` |
| `pattern3_number_triangle.cpp` | Number Triangle | Incremental numbers | `cout << j` |
| `pattern4_constant_number.cpp` | Constant Row Number | Repeated row values | `cout << i` |
| `pattern5_inverted_triangle.cpp` | Inverted Triangle | Decreasing stars | `j ≤ n - i + 1` |
| `pattern6_reverse_number.cpp` | Reverse Number Triangle | Numbers in decreasing length | `j ≤ n - i + 1` |
| `pattern7_pyramid.cpp` | Pyramid | Center-aligned triangle | Spaces = `n - i - 1`, Stars = `2*i + 1` |
| `pattern8_inverted_pyramid.cpp` | Inverted Pyramid | Upside-down version of pyramid | Spaces = `i`, Stars = `2*(n - i) - 1` |
| `pattern9_diamond.cpp` | Diamond | Pyramid + Inverted Pyramid | Symmetric combination |

---

## 📐 Pattern Formulas Summary

| Type | Spaces | Stars | Description |
|-------|---------|--------|--------------|
| Left Triangle | 0 | `i` | Simple increasing |
| Inverted Triangle | 0 | `n - i + 1` | Decreasing |
| Right-Aligned | `n - i` | `i` | Shifted right |
| Pyramid | `n - i - 1` | `2*i + 1` | Centered |
| Inverted Pyramid | `i` | `2*(n - i) - 1` | Upside down |
| Diamond | Combine | Combine | Symmetric |


## 🧩 Key Learnings

1. Every pattern has a **mathematical relationship** between rows and columns.  
2. Separate your logic into two parts — **spaces** and **symbols (stars/numbers)**.  
3. Focus on understanding **how i and j change** in nested loops.  
4. Use these problems to improve **dry run ability** and **visualize loops**.  
5. These form the foundation for **matrix, string, and recursion problems** in DSA.


## 👨‍💻 Author

**Suresh Krishna S**  
🎯 AI & DS Student | AI Enthusiast  


🌐 [Portfolio](https://sureshkrishnan.vercel.app/)  
💼 [LinkedIn](https://www.linkedin.com/in/suresh-krishnan-s/)

---
