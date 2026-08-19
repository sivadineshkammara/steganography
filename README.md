# Image Steganography

> A C-based LSB Image Steganography project that securely hides and extracts secret data within digital images without visibly altering their appearance.

[![Language](https://img.shields.io/badge/Language-C-blue)](#)
[![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)](#)
[![Status](https://img.shields.io/badge/Status-Active-success)](#)
[![License](https://img.shields.io/badge/License-MIT-green)](#)

---

## 📌 Overview

 This project implements LSB (Least Significant Bit) Image Steganography in C, a technique for concealing secret information within digital images without visibly altering their appearance.

 The project demonstrates how:

 * Secret data can be embedded into the least significant bits of image pixels.
 
 * Hidden information can be encoded into and decoded from a carrier image.
 
 * Steganography differs from cryptography by concealing the existence of the message, rather than simply encrypting its contents.
 
 * Image-based steganography exploits the limitations of human visual perception, making small pixel-level modifications difficult to notice.
 
 * The implementation balances data capacity, image quality, and reliability while applying practical C programming and file-handling concepts.

 The project is structured as a modular command-line application, focusing on low-level data manipulation, file I/O, memory management, input validation, error handling, and clean separation between encoding and decoding operations.
---

## 🎯 Objectives

The main objectives of this project are:

* Build a modular and maintainable software architecture
* Apply core C programming concepts in a practical environment
* Implement robust error handling
* Practice dynamic memory management
* Work with files and persistent data
* Use Git for version control
* Debug using industry-standard tools
* Write code that can be extended without major restructuring
* Implement LSB-based image steganography for hiding and extracting secret data from digital images.
* Understand and apply bit-level manipulation using C programming.
* Implement reliable encoding and decoding operations while preserving the visual quality of the carrier image.
* Develop practical skills in file I/O, pointers, structures, memory management, and binary data processing.
* Design a modular and maintainable command-line application with proper input validation and error handling.
* Analyze the trade-offs between data-hiding capacity, image quality, and implementation reliability.

---

## 🏗️ Architecture

```text
                    ┌─────────────────┐
                    │   User / CLI    │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Command Handler │
                    └────────┬────────┘
                             │
              ┌──────────────┼──────────────┐
              ▼              ▼              ▼
        ┌───────────┐  ┌───────────┐  ┌───────────┐
        │   Module  │  │   Module  │  │   Module  │
        │     A     │  │     B     │  │     C     │
        └─────┬─────┘  └─────┬─────┘  └─────┬─────┘
              │              │              │
              └──────────────┼──────────────┘
                             ▼
                    ┌─────────────────┐
                    │ Data / File I/O │
                    └─────────────────┘
```

---

## 📁 Project Structure

```text
project-name/
│
├── src/
│   ├── main.c
│   ├── module_a.c
│   └── module_b.c
│
├── include/
│   ├── module_a.h
│   └── module_b.h
│
├── tests/
│   └── test_module.c
│
├── docs/
│   └── architecture.md
│
├── build/
│
├── .gitignore
├── Makefile
├── README.md
└── LICENSE
```

### Directory Responsibilities

| Directory   | Purpose                                  |
| ----------- | ---------------------------------------- |
| `src/`      | Application source code                  |
| `include/`  | Header files and public interfaces       |
| `tests/`    | Unit and integration tests               |
| `docs/`     | Architecture and technical documentation |
| `build/`    | Generated build files                    |
| `Makefile`  | Build automation                         |
| `README.md` | Project documentation                    |

---

## ⚙️ Features

### Core Features

* Feature 1
* Feature 2
* Feature 3
* Feature 4

### Technical Features

* Dynamic memory allocation
* File I/O
* Input validation
* Error handling
* Modular architecture
* Logging
* Configuration management

---

## 🧠 Concepts Demonstrated

This project demonstrates practical usage of:

### C Programming

* Variables and data types
* Functions
* Pointers
* Structures
* Arrays
* Strings
* Dynamic memory
* Function pointers
* Header/source separation
* Preprocessor directives

### Systems Programming

* File descriptors / file I/O
* Memory management
* Process interaction
* Error handling
* Debugging
* Build systems

### Software Engineering

* Modular design
* Separation of concerns
* Defensive programming
* Version control
* Testing
* Documentation

---

## 🔧 Technologies & Tools

| Technology  | Purpose                 |
| ----------- | ----------------------- |
| C           | Core implementation     |
| GCC         | Compilation             |
| Make        | Build automation        |
| GDB         | Debugging               |
| Git         | Version control         |
| GitHub      | Repository management   |
| Linux / WSL | Development environment |
| VS Code     | Development environment |

---

## 💻 Requirements

Before running the project, make sure you have:

* Linux / WSL
* GCC
* Make
* Git

Check your installation:

```bash
gcc --version
make --version
git --version
```

---

## 🚀 Installation

Clone the repository:

```bash
git clone https://github.com/USERNAME/PROJECT-NAME.git
```

Enter the project directory:

```bash
cd PROJECT-NAME
```

---

## 🔨 Build

Build the project using:

```bash
make
```

Or compile manually:

```bash
gcc -Wall -Wextra -Wpedantic -g src/*.c -Iinclude -o build/project
```

---

## ▶️ Usage

Run the application:

```bash
./build/project
```

Example:

```text
$ ./build/project

==============================
       PROJECT NAME
==============================

1. Option One
2. Option Two
3. Option Three
4. Exit

Select an option:
```

---

## 🧪 Testing

Run the test suite:

```bash
make test
```

Example:

```text
Running tests...

[PASS] Input validation
[PASS] Memory allocation
[PASS] File operations
[PASS] Error handling

Tests passed: 4/4
```

---

## 🐛 Debugging

The project can be debugged using GDB.

Compile with debugging symbols:

```bash
gcc -g ...
```

Start GDB:

```bash
gdb ./build/project
```

Useful commands:

```text
break main
run
next
step
print variable
backtrace
continue
quit
```

---

## 📊 Performance / Results

Document measurable results where applicable.

| Metric            | Result |
| ----------------- | -----: |
| Build time        |  XX ms |
| Memory usage      |  XX KB |
| Test cases        |     XX |
| Test success rate |    XX% |

Avoid adding this section if you have no meaningful measurements.

---

## 🔒 Error Handling

The project implements defensive handling for:

* Invalid user input
* NULL pointers
* Memory allocation failures
* File access failures
* Invalid configuration
* Unexpected program states

Example:

```c
if (ptr == NULL)
{
    fprintf(stderr, "Memory allocation failed\n");
    return EXIT_FAILURE;
}
```

---

## 📈 Future Improvements

Planned improvements include:

* [ ] Add unit testing framework
* [ ] Improve logging system
* [ ] Add configuration file support
* [ ] Improve error reporting
* [ ] Add CI/CD pipeline
* [ ] Improve documentation
* [ ] Add performance benchmarking

---

## 🧩 Lessons Learned

Document what you actually learned while developing the project.

Examples:

* How to design modular C applications
* How pointers interact with dynamically allocated memory
* How to debug segmentation faults
* How to structure header/source files
* How to use Git effectively
* How to identify and fix memory-related bugs
* How to design software around interfaces rather than individual functions

This section is particularly valuable for **student and portfolio projects** because it shows engineering progression rather than simply presenting the final code.

---

## 📚 References

* [C Programming Language](https://en.cppreference.com/w/c)
* [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
* [GDB Documentation](https://sourceware.org/gdb/documentation/)
* [GNU Make](https://www.gnu.org/software/make/)

Add only references that you actually used.

---

## 👤 Author

**Siva Dinesh Kammara**

M.Sc. Electromobility / Embedded Systems

GitHub: [sivadineshkammara](https://github.com/USERNAME)

---

## 📄 License
Not added yet.
This project is licensed under the MIT License.

See [`LICENSE`](LICENSE) for more information.

---

## ⭐ Project Status

**Status:** 🚧 In Development

This project is actively being developed and may undergo architectural and functional changes.
