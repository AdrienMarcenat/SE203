### Adrien Marcenat ---- exercice compilation 1

**Fichier source:** t.c  
**Makefile:** make dump réalise objdump -t t.o

Résultat pour les variables y_int8, y_int32, y_short et y_long_long:
```c  
00000001       O *COM*	00000001 y_int8  
00000008       O *COM*	00000008 y_long_long  
00000004       O *COM*	00000004 y_int32  
00000002       O *COM*	00000002 y_short  
```

Les variables non initialisées sont placés en section *COM* (et non pas bss car on ne sait pas encore si un autre fichier les initialise).
La première colonne représente dans ce cas la taille, et non pas l'adresse.
