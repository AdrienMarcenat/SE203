### Adrien Marcenat ---- exercice compilation 2

**Fichier source:** t.c  
**Makefile:** make dump lance objdump -h t  
make lance t, ce qui affiche les adresses variables créées sur la pile ou le tas.


**Résultat de make dump:**  
```c
dx Nom           Taille    VMA                LMA               Fich off  Algn  
                  CONTENTS, ALLOC, LOAD, READONLY, CODE  
 12 .text         000001c2  0000000000400490    0000000000400490  00000490  2**4  
                  CONTENTS, ALLOC, LOAD, READONLY, CODE  
 14 .rodata       00000048  0000000000400660    0000000000400660  00000660  2**3  
                  CONTENTS, ALLOC, LOAD, READONLY, DATA  
 23 .data         00000010  0000000000601030    0000000000601030  00001030  2**3  
                  CONTENTS, ALLOC, LOAD, DATA  
 24 .bss          00000008  0000000000601040    0000000000601040  00001040  2**0  
```

**Résultat de make:**  
```c
adresse de x = 0x7ffefd8623dc, y = 0x7ffefd8623d8, ptr = 0x1955010, tab[0]:0x7ffefd8623d0, tab[1]:0x7ffefd8623d4
```

On remarque l'ordre suivant (par adresses croissantes):
    text, rodata, data, bss, heap, stack

De plus, les variables x et y sont créés dans cette ordre dans le code assembleur, et l'ordre de leur adresse dans la pile est inversé, la pile décroît donc. En revanche, les adresses d'un tableau alloué sur la pile croient, mais le début du tableau se situe bien à une adresse inférieure à x et y.
