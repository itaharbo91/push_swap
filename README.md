# Push Swap

Un algorithme de tri optimisé utilisant deux piles (stacks) et un ensemble d'opérations limitées pour réarranger efficacement une liste de nombres aléatoires.

## 📋 Description

**Push Swap** trie une pile de nombres entiers en utilisant seulement **deux piles** (A et B) et des opérations spécifiques. L'objectif principal est d'accomplir le tri avec le **minimum de mouvements possibles**.

## 🎯 Objectif

Passer de :
```
Stack A: [4, 67, 3, 87, 23]
Stack B: []
```

À :
```
Stack A: [3, 4, 23, 67, 87]  ✓ Trié
Stack B: []
```

## 🛠️ Opérations Disponibles

### Swaps
- `sa` : Permute les 2 premiers éléments de A
- `sb` : Permute les 2 premiers éléments de B
- `ss` : Exécute `sa` et `sb` simultanément

### Push
- `pa` : Pousse le premier élément de B vers A
- `pb` : Pousse le premier élément de A vers B

### Rotate
- `ra` : Décale tous les éléments de A vers le haut (le premier va en dernier)
- `rb` : Décale tous les éléments de B vers le haut
- `rr` : Exécute `ra` et `rb` simultanément

### Reverse Rotate
- `rra` : Décale tous les éléments de A vers le bas (le dernier va en premier)
- `rrb` : Décale tous les éléments de B vers le bas
- `rrr` : Exécute `rra` et `rrb` simultanément

## 🧠 Ma Logique d'Algorithme

### 1️⃣ Cas Spéciaux (≤ 5 éléments)
Pour les petites listes, utilisation de tri directs optimisés :
- **Taille 2** : Un simple swap si nécessaire
- **Taille 3** : Combinaison de rotates et swaps (max 2 opérations)
- **Taille 4** : Push du minimum en B, tri du reste, retour (max 6 opérations)
- **Taille 5** : Push de 2 minimums en B, tri du reste, retour en ordre (max 12 opérations)

### 2️⃣ Cas Général (> 5 éléments) - Divide & Conquer

#### Phase 1 : Division par la médiane
```
1. Calculer la médiane de la pile A
2. Pousser tous les éléments < médiane vers B
3. Pousser tous les éléments >= médiane vers B
```

#### Phase 2 : Tri via "Best Index"
Le cœur de l'algorithme : **choisir le meilleur élément à déplacer**

Pour chaque élément en B, calculer le **coût total** de déplacement :
```
coût = rotations_nécessaires_en_B + rotations_nécessaires_en_A
```

**Sélectionner l'élément avec le coût minimal** et l'insérer à la bonne position en A.

#### Phase 3 : Optimisation des rotations
Lorsque A et B ont tous deux besoin de rotations :
- Si tous les deux ont besoin de **rotate** : utiliser `rr` (2 opérations en 1)
- Si tous les deux ont besoin de **reverse rotate** : utiliser `rrr` (2 opérations en 1)

#### Phase 4 : Finition
```
1. Pousser tous les éléments restants de B vers A
2. Placer le minimum de A en haut (première position)
```

### 📊 Exemple d'Optimisation

Sans optimisation :
```
ra          (10 fois)
rb          (5 fois)
pb
...
Total: 15 opérations
```

Avec optimisation (rr/rrr) :
```
rr          (5 fois)
ra          (5 fois)
pb
...
Total: 11 opérations
```

## 🚀 Installation & Compilation

```bash
# Compiler le programme principal
make

# Compiler avec le bonus (checker program)
make bonus

# Nettoyer les fichiers objets
make clean

# Nettoyer complètement
make fclean

# Recompiler
make re
```

## 💻 Utilisation

### Programme Principal
```bash
./push_swap 4 67 3 87 23
# Affiche la séquence optimale d'opérations :
# pb
# pb
# ra
# pa
# pa
```

Avec des paramètres en tant que chaîne :
```bash
./push_swap "4 67 3 87 23"
```

### Programme Bonus - Checker
```bash
./checker 4 67 3 87 23
# Lit les opérations depuis l'entrée standard
# Affiche "OK" si la liste est triée, "KO" sinon

echo -e "pb\npb\nra\npa\npa" | ./checker 4 67 3 87 23
# OK
```

## 📈 Complexité

- **Petites listes** (n ≤ 5) : O(1) en nombre d'opérations (max fixe)
- **Grandes listes** (n > 5) : O(n²) en moyenne
  - Calcul du meilleur index : O(n)
  - Nombre d'itérations : O(n)

## ✨ Optimisations Appliquées

✅ **Utilisation de médiane** pour équilibrer la division
✅ **Meilleur index** : sélection de l'élément au coût minimal
✅ **Rotations doubles** (rr/rrr) pour réduire les mouvements
✅ **Choix du sens** : rotate vs reverse_rotate basé sur la position (haut/bas de la pile)
✅ **Gestion mémoire** : allocation dynamique, pas de fuite

## 🧪 Test

```bash
# Test simple
./push_swap 3 2 1

# Test avec nombres négatifs
./push_swap -3 -2 -1 0 1

# Test avec duplicatas (génère une erreur)
./push_swap 1 2 2 3
# Error (car duplicatas interdits)

# Test avec non-entiers (génère une erreur)
./push_swap 1 2 abc 3
# Error
```

## 📚 Structure du Projet

```
push_swap/
├── Makefile                    # Compilation
├── srcs/
│   ├── main.c                  # Point d'entrée
│   ├── push_swap.h             # Header principal
│   ├── error_code.c            # Validation des inputs
│   ├── instructions/           # Opérations (sa, sb, pa, pb, ra, rb, etc.)
│   ├── sort/
│   │   ├── sort_small.c        # Tri direct (n ≤ 5)
│   │   ├── sort_all.c          # Tri par médiane et best_index
│   │   ├── best_index.c        # Sélection du meilleur élément
│   │   └── rotate_to_top.c     # Rotation optimisée
│   ├── tab/                    # Parsing et conversion
│   ├── utils/                  # Utilitaires (find_median, etc.)
│   └── opti/                   # Optimisations (rr, rrr)
└── bonus/                      # Programme checker
```

## 🎓 École 42

Projet du Common Core - Cercle 2

## 📌 Points Clés

- ✅ Gestion des erreurs robuste
- ✅ Pas de fuite mémoire
- ✅ Optimisation maximale du nombre d'opérations
- ✅ Code bien structuré et modulaire
- ✅ Programme bonus (checker) pour valider les solutions

## 👤 Auteur

[@itaharbo91](https://github.com/itaharbo91)

---

**Description GitHub** : Stack-based sorting algorithm with optimized divide-and-conquer strategy using limited operations.
