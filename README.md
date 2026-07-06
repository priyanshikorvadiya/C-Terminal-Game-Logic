# C-Terminal-Game-Logic

# 🎮 Enhanced Terminal Anagram Game in C

A highly optimized, interactive command-line Anagram Game built in **C**. The game utilizes ANSI escape sequence rendering for a clean terminal GUI experience, featuring dynamic dashboards, score tracking, and automated hints.

---

## ⚡ Core Logic & Enhancements

* **Linear Frequency Checker:** Evaluates string lengths first (O(1)) and implements character frequency validation using a 26-sized static bucket index to guarantee accurate anagram verification in O(n) time.
* **Fisher-Yates Scrambler:** Uses a modern in-place pointer shuffling algorithm to dynamically create randomized letter hints for users.
* **Identical Submission Guard:** Explicitly utilizes memory block comparison (`strcmp`) to block users from entering the exact original target word.
* **Terminal UI Injection:** Implements macro-defined ANSI graphics (`\033[...]`) for custom header states, color-coded score updating, and instant frame buffering via screen-clear sequences.

---

## 🗂️ Project Structure & Execution

* `main.c` - Contains the full driver engine, dynamic structures, scrambler functions, and state loops.

### Build and Run Steps
1. Compile using GCC:
```bash
gcc main.c -o anagram_game
