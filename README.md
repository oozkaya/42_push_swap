# push_swap @ 42

Ce projet demande de trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles.
Pour le réussir, il faudra manipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données.

## Partie obligatoire :

* Le jeu est constitué de 2 piles nommées a et b.
* Au départ :
    - a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
    - b est vide
* Le but du jeu est de trier a dans l’ordre croissant.
* Pour ce faire, on ne dispose que des opérations suivantes :
    - **sa : swap a** - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
      rien s’il n’y en a qu’un ou aucun.
    - **sb : swap b** - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
      rien s’il n’y en a qu’un ou aucun.
    - **ss** : **sa** et **sb** en même temps.
    - **pa : push a** - prend le premier élément au sommet de b et le met sur a. Ne fait
      rien si b est vide.
    - **pb : push b** - prend le premier élément au sommet de a et le met sur b. Ne fait
      rien si a est vide.
    - **ra : rotate a** - décale d’une position vers le haut tous les élements de la pile a.
      Le premier élément devient le dernier.
    - **rb : rotate b** - décale d’une position vers le haut tous les élements de la pile b.
      Le premier élément devient le dernier.
    - **rr** : **ra** et **rb** en même temps.
    - **rra : reverse rotate a** - décale d’une position vers le bas tous les élements de
      la pile a. Le dernier élément devient le premier.
    - **rrb : reverse rotate b** - décale d’une position vers le bas tous les élements de
      la pile b. Le dernier élément devient le premier.
    - **rrr** : **rra** et **rrb** en même temps.

Exemple :

![Alt text](https://image.ibb.co/b1gjMJ/example_ps.jpg)

---

---

Le projet se divise en 2 programmes, **./push_swap et ./checker** :

* **./checker** attendre de lire des instructions sur l’entrée standard et va les exécuter sur la pile d’entiers passée en paramètres. Si après exécution la pile a est bien triée et la pile b est vide, alors **./checker** doit afficher **"OK"** sinon **"KO"**.

![Alt text](https://image.ibb.co/k62Yyy/checker.png)

* **./push_swap**  doit afficher le programme composé de la **plus petite suite d’instructions possible** qui permet de trier la pile a.

![Alt text](https://image.ibb.co/cou7Qd/Untitled.png)

![Alt text](https://image.ibb.co/esbOWJ/Untitled.png)

* Si **./checker** devait afficher **"KO"**, cela signifirait que **./push_swap** a calculé un programme qui ne trie pas la liste et qui est donc faux.

---

---

Barème version avancée sur 5 points :

* **500 entiers** : 5500 | 7000 | 8500 | 10000 | 11500
* **100 entiers** : 700 | 900 | 1100 | 1300 | 1500

Mon push_swap :

* **500 entiers** : environ 4400 opérations
* **100 entiers** : environ 600 opérations

---

---

## Bonus :

* **Usage PUSH_SWAP**:
    - ./push_swap [options] [arg1] [arg2] ...

* **Options** :
    - -f [filename.txt] pour écrire sur un fichier

---

* **Usage CHECKER**:
    - ./checker [options] [arg1] [arg2] ...

* **Options** :
    - -v pour utiliser le visualisateur
    - -c pour afficher l'instruction en cours sur le terminal
    - -f [filename.txt] pour lire depuis un fichier

---

* **Visualisateur** :

    - **Entrée (numpad)** : play

    - **Espace** : pause

    - **Flèche droite**: avance de 1 instruction

    - **Vitesse 1-6 (numpad)**: 1 etant le plus lent, 6 le plus rapide
    
[![https://gyazo.com/784697b3ca0232e28a4dbddb0b40746a](https://i.gyazo.com/784697b3ca0232e28a4dbddb0b40746a.gif)](https://gyazo.com/784697b3ca0232e28a4dbddb0b40746a)

---

---

## Utilisation


> $> git submodule init

> $> git submodule update

> $> make

puis :

> $> ARG=\`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"\` | ./push_swap $ARG | ./checker -v $ARG

ou :

> $> sh analyser.sh