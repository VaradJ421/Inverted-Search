# Inverted-Search
Built an Inverted Search system to perform fast word-based file searching. Implemented linked lists and hash table concepts for efficient indexing and retrieval. Supported keyword search across multiple files with optimized search complexity. Developed using C language with file handling and DSA concepts.
# 🔎 Inverted Search

A **C-based Inverted Search system** designed to perform fast **word-based searching across multiple files** using **hash tables and linked lists**.

The project creates an inverted index that maps each searchable word to the files in which it appears. This approach avoids repeatedly scanning every file for every search query and enables efficient keyword-based information retrieval.

This project was developed as part of my **Embedded Systems training at Emertxe Information Technologies**, strengthening my understanding of **Data Structures and Algorithms (DSA), file handling, linked lists, hash tables, pointers, and dynamic memory management**.

## 📌 Project Overview

A traditional file search approach scans each file whenever a keyword is searched.

An **Inverted Search** approach builds an index beforehand:

```text
Keyword → Files containing the keyword
```

For example:

```text
"embedded"
     │
     ├── file1.txt
     ├── file3.txt
     └── file5.txt
```

When the user searches for a word, the program looks up the word in the index instead of scanning all files from scratch.

## ✨ Features

* 🔍 Fast keyword-based searching
* 📂 Search across multiple text files
* 🗂️ Create an inverted index
* 📊 Hash table-based indexing
* 🔗 Linked-list-based file tracking
* ➕ Insert words into the index
* 🔎 Search for keywords
* 📋 Display indexed data
* 💾 File handling support
* ⚠️ Input validation
* 🧠 Dynamic memory management

## 🧠 What is Inverted Search?

An **inverted index** is a data structure that maps a word or keyword to the documents/files where it occurs.

### Normal Search

```text
Search "C"

File 1 → Scan
File 2 → Scan
File 3 → Scan
File 4 → Scan
File 5 → Scan
```

### Inverted Search

```text
             Inverted Index
                  │
                  ▼
             Hash Table
                  │
                  ▼
             "C"
                  │
        ┌─────────┼─────────┐
        ▼         ▼         ▼
     File 1    File 3    File 5
```

This makes repeated keyword searches more efficient.

## 🏗️ System Architecture

```text
                    Input Files
                        │
                        ▼
                ┌───────────────┐
                │ File Handling │
                └───────┬───────┘
                        │
                        ▼
                 Extract Words
                        │
                        ▼
                ┌───────────────┐
                │  Hash Function│
                └───────┬───────┘
                        │
                        ▼
                 ┌─────────────┐
                 │ Hash Table   │
                 └──────┬──────┘
                        │
             ┌──────────┴──────────┐
             ▼                     ▼
        Word Node              File Nodes
             │                     │
             └──────────┬──────────┘
                        ▼
                  Search Query
                        │
                        ▼
                  Search Results
```

## 🔄 How It Works

### Step 1: Read Input Files

The application accepts multiple text files as input.

```text
file1.txt
file2.txt
file3.txt
```

### Step 2: Extract Words

The program reads each file and extracts individual words.

```text
"Embedded systems are powerful"

        ↓

Embedded
systems
are
powerful
```

### Step 3: Generate Hash Index

Each word is processed through a hash function to determine its location in the hash table.

```text
Word
 │
 ▼
Hash Function
 │
 ▼
Hash Index
```

### Step 4: Build Linked Lists

If multiple words map to the same hash index, linked lists are used to manage collisions.

```text
Hash Table
   │
   ├── Index 0
   ├── Index 1 → Word → File → File
   ├── Index 2
   ├── Index 3 → Word → File
   └── ...
```

### Step 5: Search

When the user enters a keyword, the program calculates its hash index and searches the corresponding linked-list structure.

```text
Search Word
     │
     ▼
Hash Function
     │
     ▼
Hash Index
     │
     ▼
Linked List
     │
     ▼
Matching Files
```

## 📚 Data Structures Used

### Hash Table

The hash table provides efficient indexing of words.

```text
Index
  0
  1 → word
  2
  3 → word
  4 → word
  ...
```

### Linked List

Linked lists are used to handle:

* Hash collisions
* Multiple files containing the same word
* Dynamic file associations

Example:

```text
"network"
    │
    ▼
File1.txt → File3.txt → File7.txt → NULL
```

## 🛠️ Technologies & Concepts

| Category             | Details                       |
| -------------------- | ----------------------------- |
| Programming Language | C                             |
| Interface            | Command Line                  |
| Data Structures      | Hash Table, Linked List       |
| Algorithms           | Hashing, Searching            |
| File Handling        | C File I/O                    |
| Memory               | Dynamic Memory Allocation     |
| Core Concepts        | Pointers, Structures, Strings |
| Platform             | Linux / GCC                   |

## 🔧 Key Concepts Demonstrated

### 1. Hashing

A hash function maps a word to an index in the hash table.

```text
Keyword
   │
   ▼
Hash Function
   │
   ▼
Index
```

This reduces the search space compared with scanning every stored word sequentially.

### 2. Collision Handling

Different words may produce the same hash index.

Linked lists can be used to handle these collisions:

```text
Hash Index 5
     │
     ▼
   Word A
     │
     ▼
   Word B
     │
     ▼
   Word C
     │
     ▼
    NULL
```

### 3. Dynamic Memory Allocation

Dynamic structures allow the index to grow based on the input data.

Common C functions include:

```c
malloc()
calloc()
realloc()
free()
```

### 4. File Handling

The application reads and processes multiple files using C file operations such as:

```c
fopen()
fread()
fscanf()
fseek()
fclose()
```

## 📁 Project Structure

```text
Inverted-Search/
│
├── main.c
├── create_database.c
├── display_database.c
├── search_database.c
├── update_database.c
├── save_database.c
├── types.h
├── common.h
├── Makefile
└── README.md
```

> Update the structure above according to the actual files in your repository.

## ⚙️ Installation & Setup

### Clone the Repository

```bash
git clone https://github.com/VaradJ421/Inverted-Search.git
```

### Navigate to the Project

```bash
cd Inverted-Search
```

### Compile

If a Makefile is available:

```bash
make
```

Or compile using GCC:

```bash
gcc *.c -o inverted_search
```

### Run

```bash
./inverted_search
```

> Adjust the commands according to the exact build process implemented in your project.

## 🧪 Example

Suppose the following files are provided:

```text
file1.txt
```

contains:

```text
Embedded systems use C.
```

`file2.txt` contains:

```text
C is widely used in embedded systems.
```

After indexing:

```text
Word: embedded
    ├── file1.txt
    └── file2.txt

Word: systems
    ├── file1.txt
    └── file2.txt

Word: C
    ├── file1.txt
    └── file2.txt
```

Searching for:

```text
embedded
```

returns:

```text
embedded found in:

1. file1.txt
2. file2.txt
```

## 📊 Search Approach

| Approach         | Traditional Search  | Inverted Search           |
| ---------------- | ------------------- | ------------------------- |
| Indexing         | No                  | Yes                       |
| File Scanning    | Repeated            | Primarily during indexing |
| Search           | Sequential scanning | Hash-based lookup         |
| Data Structure   | Basic file access   | Hash Table + Linked List  |
| Repeated Queries | Less efficient      | More efficient            |

The actual performance depends on the hash function, collision rate, number of files, and implementation details.

## 🎯 Project Objectives

The main objectives of this project were to:

* Understand inverted indexing.
* Implement hash tables in C.
* Implement linked lists.
* Handle hash collisions.
* Search keywords across multiple files.
* Work with file handling.
* Practice pointers and structures.
* Apply DSA concepts to a real-world problem.

## ⚠️ Limitations

* Primarily designed for text-file searching.
* Search behavior depends on word parsing implemented in the project.
* Performance depends on hash-function quality and collision handling.
* The current implementation may not support advanced search features such as phrase search or fuzzy search.

## 🚀 Future Enhancements

Possible improvements include:

* [ ] Add phrase searching
* [ ] Add case-insensitive search
* [ ] Add fuzzy/approximate search
* [ ] Add Boolean search (`AND`, `OR`, `NOT`)
* [ ] Improve hash-function performance
* [ ] Add index persistence
* [ ] Add ranking of search results
* [ ] Add support for larger datasets
* [ ] Add automated test cases
* [ ] Add search statistics

## 🎓 Learning Outcomes

Through this project, I gained practical experience in:

* C programming
* Data Structures and Algorithms
* Hash tables
* Linked lists
* Hash functions
* Collision handling
* File handling
* Pointers
* Structures
* Dynamic memory allocation
* String processing
* Search optimization
* Algorithmic problem-solving

## 💡 Key Takeaway

This project provided practical experience in applying **Data Structures and Algorithms to a real-world file-search problem**.

By implementing an inverted index using **hash tables and linked lists**, I learned how appropriate data structures can significantly improve the organization and retrieval of information.

## 👨‍💻 Author

**Varad Umesh Jinturkar**

Embedded Systems | C Programming | Data & AI Enthusiast

GitHub: **[@VaradJ421](https://github.com/VaradJ421)**

## ⭐ Support

If you find this project useful for learning **C programming, DSA, hash tables, linked lists, or information retrieval**, consider giving the repository a ⭐.
