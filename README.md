# Contrôle continu de Synthèse d'Images

## Compilation

Pour compiler le programme:

```shell
  make
```

Pour exécuter le programme:

```shell
  ./build/PlaymobilCGI
```

Le programme se ferme en appuyant sur la touche `ESCAPE`.

La commande `make clean` supprime les dossiers `build` et `obj` crées lors de la compilation.

## Commandes

### Manipulation de la caméra

La caméra se contrôle de la manière suivante:

```
  - KEY_UP : rotation selon l'axe 'X' de 10.0°
  - KEY_DOWN : rotation selon l'axe 'X' de -10.0°
  - KEY_RIGHT : rotation selon l'axe 'Y' de 10.0°
  - KEY_LEFT : rotation selon l'axe 'Y' de -10.0°
  - b : rotation selon l'axe 'Z' de 10.0°
  - r : rotation selon l'axe 'Z' de -10.0°
```

### Manipulation de la lumière

La lumière se contrôle de la manière suivante:

```
  - l : passe du mode lumière omnidirectionnelle à un modèle de Phong
```

Par défaut le modèle de lumière est `omnidirectionnelle`

### Manipulation du playmobil

Le playmobil se contrôle de la manière suivante :

```
  - z : le playmobil avance en avant
  - s : le playmobil avance en arrière
  - q : le playmobil tourne selon l'axe 'Z'
  - d : le playmobil tourne selon l'axe 'Z' dans le sens contraire
```

## Contenu du programme

Le programme contient:
 - Une caméra qui peut se déplacer selon 3 axes.
 - Un playmobil qui se déplace en avant et en arrière et qui peut tourner sur lui même.
 - Une réplique du playmobil qui avance et recule seule.
 - 4 murs et un sol, tous les 5 texturés.

### Le playmobil

Le playmobil est conçu de sorte à ce que les bras et jambes se balancent lors du mouvement.

### La scène

La scène comporte un sol, entièrement texturé. Ce sol est un pavé droit et comporte donc toutes ses faces.
Les murs ne sont représenté que sous une face, de telle sorte que la caméra et la lumière ne soient jamais obstruées.
Les murs représentent les limites physique de la scène. Le playmobil ne peut pas les traverser.
