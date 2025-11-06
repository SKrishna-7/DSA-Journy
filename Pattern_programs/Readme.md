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

## 🧩 Patterns Overview

| File Name | Pattern Type | Description | Formula / Concept |
|------------|---------------|--------------|-------------------|
| `Rectangular_star.cpp` | Square | Solid block of `*` | `i ≤ n`, `j ≤ n` |
| `RightTriangle.cpp` | Right Triangle | Increasing stars | `j ≤ i` |
| `Number_triangle.cpp` | Number Triangle | Incremental numbers | `cout << j` |
| `Constant_number.cpp` | Constant Row Number | Repeated row values | `cout << i` |
| `inverted_triangle.cpp` | Inverted Triangle | Decreasing stars | `j ≤ n - i + 1` |
| `number_pattern.cpp` | Reverse Number Triangle | Numbers in decreasing length | `j ≤ n - i + 1` |
| `pyramid.cpp` | Pyramid | Center-aligned triangle | Spaces = `n - i - 1`, Stars = `2*i + 1` |
| `inverted_pyramid.cpp` | Inverted Pyramid | Upside-down version of pyramid | Spaces = `i`, Stars = `2*(n - i) - 1` |
| `diamond.cpp` | Diamond | Pyramid + Inverted Pyramid | Symmetric combination |
| `binary_triangle.cpp` | Binary Triangle | Alternating 1s and 0s | Toggle `start` between 1 and 0 |
| `number_crown.cpp` | Number Crown | Mirrored numbers with spaces | Spaces = `2*(n - i)` |
| `continuous_number.cpp` | Continuous Numbers | Counting across rows | Increment global counter |
| `alpha_triangle.cpp` | Alphabet Increasing Triangle | Letters from A to A+i | `cout << 'A' + j` |
| `alpha_ramp.cpp` | Constant Character Row | Repeat same character in each row | `'A' + i` |
| `alpha_hill.cpp` | Alphabet Hill Pattern | Symmetric letters (A→...→A) | Midpoint = `(2*i+1)/2` |
| `increasing_char_triangle.cpp` | Alphabetic Sequence | Increasing letters in each row | `for(char j='A'; j<'A'+i; j++)` |
| `hollow_rectangle.cpp` | Hollow Rectangle | Border stars, empty inside | ` if(i==0 or j==0 or i==n-1 or j==n-1) ` |
| `symmetric_void.cpp` | Symmetric Void | Stars shrink and expand with spaces | `space = 2*(n - i)` |
| `symmetric_butterfly.cpp` | Butterfly Pattern | Expanding and shrinking mirrored triangles | `stars = min(i, 2n - i)` |
| `number_pattern.cpp` | Mixed Numeric Patterns | Combo of mirrored and pyramid patterns | Combination of number logics |

---

## 📐 Pattern Logic Formulas Summary

| Type | Spaces | Stars | Description |
|-------|---------|--------|--------------|
| Left Triangle | 0 | `i` | Simple increasing |
| Inverted Triangle | 0 | `n - i + 1` | Decreasing |
| Right-Aligned | `n - i` | `i` | Shifted right |
| Pyramid | `n - i - 1` | `2*i + 1` | Centered |
| Inverted Pyramid | `i` | `2*(n - i) - 1` | Upside down |
| Diamond | Combine | Combine | Symmetric |
| Butterfly | Expanding then contracting | `min(i, 2n - i)` | Dual symmetry |
| Binary | - | - | Alternating 1s and 0s |
| Alphabets | - | - | Character arithmetic using ASCII |

---

## 🧠 Concepts Practiced

- Nested Loop Logic (`for i`, `for j`)
- Symmetry and mirroring with `2n - i`
- Variable space and star manipulation
- Character arithmetic (`'A' + i`)
- Alternating binary and numeric patterns
- Compound patterns (Butterfly, Crown, Diamond)

---

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
