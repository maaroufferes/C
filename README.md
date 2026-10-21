# C Programming Lab Projects

A collection of practical exercises (Travaux Pratiques) completed during my university studies, implemented in C. Each project focuses on core programming concepts such as data structures, arrays, string manipulation, and algorithmic problem solving.

## Projects

| File | Description |
|------|-------------|
| `Bibliotheque.c` | Library management system for adding, searching, and managing books |
| `ADN.c` | Computes the complementary strand of a given DNA sequence |
| `Employe.c` | Employee management system handling employee records and salaries |
| `Etudiants.c` | Student grade analysis: number of passing students, top performer, and other statistics |
| `Solution.c` | Solver for quadratic equations |
| `Tableau.c` | Common array operations such as traversal, search, sorting, and modification |

## Concepts Covered

- Arrays and strings
- Structures (`struct`)
- Conditional statements and loops
- Functions and modular programming
- Input/output handling

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Compilation and Execution

```bash
gcc <filename>.c -o <output_name>
./<output_name>
```

Example:

```bash
gcc ADN.c -o adn
./adn
```

> For `Solution.c`, add the `-lm` flag if the program uses `math.h` (e.g., `sqrt`):
> `gcc Solution.c -o solution -lm`

## Repository Structure

```
.
├── Bibliotheque.c
├── ADN.c
├── Employe.c
├── Etudiants.c
├── Solution.c
├── Tableau.c
└── README.md
```

## License

This project is intended for educational purposes.
