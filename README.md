# CSES-Solutions 🚀

This repository contains my accepted C++ solutions to various problems from the [CSES Problem Set](https://cses.fi/problemset/). It's part of my journey toward mastering algorithms and data structures while preparing for coding interviews and competitive programming.

## 📁 Structure

Each `.cpp` file in this repo corresponds to a problem from the CSES sheet.

### ✅ Current Implemented Solutions:
- `Forest_Queries.cpp`: Handles 2D prefix sums for rectangular queries on grids.
- `Subarray_Sum_Queries.cpp`: Uses prefix sums to solve subarray sum count problems.
- `Dynamic_Range_Sum_Queries.cpp`: Implements a Fenwick Tree (Binary Indexed Tree) for efficient point updates and range sum queries.

## 🔧 Technologies Used
- **Language**: C++17
- **Compiler**: g++ / MSVC (locally on Windows)
- **Version Control**: Git

## ⏱️ Time Complexities
| Problem                          | Update | Query |
|----------------------------------|--------|--------|
| Dynamic Range Sum Queries        | O(log n) | O(log n) |
| Forest Queries (2D Prefix Sum)   | O(1)   | O(1) |
| Subarray Sum Queries             | Preprocessing: O(n), Queries: O(1) |

## 💡 Highlights
- Uses 64-bit integers (`long long`) where needed to avoid overflow (especially in Fenwick Tree).
- Modular, test-friendly code.
- Ready-to-run with sample test cases.

## 🛠️ How to Run

```bash
g++ filename.cpp -o output
./output
