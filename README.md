# 🌐 Browser Simulator — DSA Project

A command-line browser simulator built in **C** that demonstrates core Data Structures and Algorithms concepts — specifically **Stacks** and **Binary Search Trees (BST)** — through a realistic browser navigation model.

---

## 📚 Data Structures Used

| Feature | Data Structure | Reason |
|---|---|---|
| Back navigation | Stack (`backStack`) | LIFO — last visited page is the first to go back to |
| Forward navigation | Stack (`forwardStack`) | LIFO — restores pages in reverse order of backtracking |
| Bookmarks | Binary Search Tree | Fast O(log n) insert and search by bookmark name |

---

## 🗂️ Project Structure

```
.
├── main.c        # Entry point; menu-driven CLI
├── browser.c     # Core browser logic
├── browser.h     # Browser struct and function declarations
├── stack.c       # Stack implementation (linked list-based)
├── stack.h       # Stack struct and function declarations
├── bst.c         # BST implementation for bookmarks
└── bst.h         # BST struct and function declarations
```

---

## ⚙️ How It Works

### Navigation (Stack)
- Every time you **visit a new page**, the current page is pushed onto the `backStack`.
- **Going back** pops from `backStack` and pushes the current page onto `forwardStack`.
- **Going forward** pops from `forwardStack` and pushes the current page onto `backStack`.
- Visiting a **new page clears** the `forwardStack` — just like a real browser.

### Bookmarks (BST)
- Bookmarks are stored as `(name, url)` pairs in a BST, ordered alphabetically by name.
- **Insert** and **search** both run in **O(log n)** average time.
- **In-order traversal** prints all bookmarks in alphabetical order.

---

## 🚀 Getting Started

### Prerequisites
- GCC or any C99-compatible compiler

### Compile

```bash
gcc main.c browser.c stack.c bst.c -o browser_sim
```

### Run

```bash
./browser_sim
```

---

## 🖥️ Menu Options

```
1. Visit Page       — Navigate to a URL
2. Go Back          — Return to the previous page
3. Go Forward       — Move forward after going back
4. Add Bookmark     — Save a name-URL pair
5. Open Bookmark    — Visit a saved bookmark by name
6. List Bookmarks   — Print all bookmarks (alphabetical order)
7. Status           — Show current page and top of each stack
8. Exit             — Quit the program
```

### Example Session

```
Choice: 1
Enter URL: google.com
---> Visiting: google.com

Choice: 1
Enter URL: github.com
---> Visiting: github.com

Choice: 2
<--- Back to: google.com

Choice: 3
---> Forward to: github.com

Choice: 4
Name: gh
URL: github.com
[+] Bookmark added: gh

Choice: 6
--- Bookmarks ---
[gh] -> github.com
```

---

## 🧠 Concepts Demonstrated

- **Linked-list based Stack** with dynamic memory allocation
- **Recursive BST** insertion and search
- **In-order traversal** for sorted output
- **Struct-based modular design** in C
- **Separation of concerns** across multiple `.c`/`.h` files

---

## 🔮 Possible Extensions

- [ ] Delete a bookmark (BST deletion)
- [ ] Persistent bookmarks via file I/O
- [ ] Browser history log (doubly linked list)
- [ ] Tab management (array of browser instances)
- [ ] Bookmark frequency tracking (augmented BST)

---
