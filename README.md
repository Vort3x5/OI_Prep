# OI_Prep

**Kolekcja algorytmów competitive programming do Olimpiady Informatycznej**

Zbiór gotowych implementacji algorytmów w C++ - każdy branch = jeden algorytm/problem.

## Zakres tematyczny

**Grafy:** 2-SAT, Bridges, Centroid, HLD, MST, Floyd-Warshall, Euler  
**Drzewa:** Segment Tree (static/dynamic), Fenwick, LCA, DP on Trees
**Stringi:** KMP, KMR, Hashing  
**Geometria:** Convex Hull  
**Inne:** Bitmask DP, LIS, Mo's Algorithm  

## Struktura

```
każdy branch = osobna implementacja
├── 2sat          → 2-SAT solver
├── HLD           → Heavy-Light Decomposition
├── Drzewo_PP     → Segment Tree lazy prop
├── KMP           → String matching
├── ConvexHull    → Graham scan
└── ...           → 30+ algorytmów
```

[Zobacz wszystkie brancha →](https://github.com/Vort3x5/OI_Prep/branches)

## Użycie

```bash
# Wybierz branch z algorytmem
git checkout HLD

# Kompiluj i uruchom
g++ -std=c++17 -O2 main.cpp -o sol
./sol < input.txt
```
