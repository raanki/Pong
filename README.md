# 🏓🤖🎾Pong

## Table des matières
- Comment installer ?
  - Windows
  - Linux
- Présentation du code
- Intelligence Artificielle (IA)
- Sons

## *Comment installer ?*

### Windows :

Cloner le repo et lancer simplement l'executable `Main.exe`

### Linux :

Juste plus long mais tout aussi simple :

- Ouvrir un terminal 
- Installer raylib <br>
Assurez-vous d'avoir les droits d'administration (sudo) pour installer les dépendances nécessaires. Cette commande effectuera toutes les étapes d'installation de raylib et exécutera l'exemple `core_basic_window` à la fin.

> Note: Si vous utilisez un autre compilateur que gcc, veuillez adapter la commande en conséquence.

Après l'exécution de la commande, vous aurez un exécutable généré incluant raylib. Vous pouvez ensuite exécuter cet exécutable en utilisant `./executable`.<br><br>
```bash sudo apt update && sudo apt install -y build-essential cmake git libasound2-dev libpulse-dev libaudio-dev libx11-dev libxrandr-dev libxcursor-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev && git clone https://github.com/raysan5/raylib.git && cd raylib && cmake . && make && sudo make install && cd examples && make && ./core_basic_window. ```

- Compiler et executer le main : <br> <br>`g++ Main.cpp -o pong -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 && ./pong` <br>


# *Maintenant Jouer !*

Voici a quoi ressemble le jeu : 

<p align="center"><img src="img/jeu.PNG" alt="jeu.png" width="500" height="300" /></p>


# Présentation du code

*Ceci est une brève présentation du code de mon jeu interactif. Pour plus de détails, veuillez consulter le fichier source complet ou me contacter.*

La section des `#include` :
- `iostream`, `string`, `vector` : bibliothèques standard de C++ utilisées pour les entrées/sorties et la manipulation de chaînes et de vecteurs.
- `cstdlib`, `ctime` : bibliothèques standard de C++ utilisées pour la gestion du temps et des fonctions aléatoires.
- `"raylib.h"` : framework raylib.

Définition des constantes :
- `LARGEUR_ECRAN` : la largeur de l'écran du jeu.
- `HAUTEUR_ECRAN` : la hauteur de l'écran du jeu.
- `vitesseRaquetteGauche` : la vitesse de déplacement de la raquette gauche.
- `vitesseRaquetteDroite` : la vitesse de déplacement de la raquette droite.
- `scoreForWin` : le score nécessaire pour gagner le jeu.

Déclaration des variables :
- `scoreJoueur`, `scoreIa` : les scores du joueur et de l'IA.
- `etatJeu` : l'état actuel du jeu.
- `vitesseBalleX`, `vitesseBalleY` : les vitesses de déplacement de la balle.
- `resultatVisible` : indique si le résultat est visible ou non.
- `balle`, `raquetteGauche`, `raquetteDroite` : les rectangles représentant la balle et les raquettes.
- `texteResultat` : le texte affiché pour le résultat.
- `sonDefaite`, `sonMur`, `sonOut`, `sonPing`, `sonVictoire` : les sons utilisés dans le jeu.

Définition des fonctions :
- `draw()` : dessine les éléments du jeu à l'écran.
- `update()` : met à jour l'état du jeu à chaque frame.
- `load()` : charge les ressources nécessaires pour le jeu.
- `unload()` : décharge les ressources utilisées par le jeu.
- `collision(Rectangle B, Rectangle G)` : vérifie s'il y a collision entre les rectangles B et G.
- `rebondSurRaquette(bool cotejoueur)` : gère le rebond de la balle sur les raquettes.
- `relancerBalle()` : replace la balle au point de départ.

Fonction principale `main()` :
Charge les ressources avec `load()`.
Boucle principale du jeu avec `update()` et `draw()`.
Décharge les ressources avec `unload()` à la fin.

## Intelligence Artificielle (IA)

Dans le code présenté, l'IA est utilisée pour contrôler la raquette droite du jeu. L'objectif de l'IA est de suivre la balle et de réagir en conséquence pour essayer de la renvoyer vers le joueur. Voici comment cela fonctionne :

- À chaque mise à jour du jeu, l'IA compare la position de la balle avec celle de sa raquette.
- Si la balle est au-dessus de la moitié supérieure de la raquette, l'IA déplace sa raquette vers le haut pour intercepter la balle.
- Si la balle est en dessous de la moitié inférieure de la raquette, l'IA déplace sa raquette vers le bas pour tenter de renvoyer la balle.

Cette logique simple permet à l'IA de réagir en temps réel et d'essayer de maintenir le jeu compétitif pour le joueur.

## Sons

Le jeu utilise différents sons pour améliorer l'expérience utilisateur. Voici une description des sons utilisés dans le code :

- `sonDefaite` : Ce son est joué lorsque le joueur perd la partie en atteignant le score maximum de l'IA. Il indique la défaite du joueur.
- `sonMur` : Ce son est joué lorsque la balle rebondit contre un mur, que ce soit en haut, en bas ou sur les côtés de l'écran.
- `sonOut` : Ce son est joué lorsque la balle sort de l'écran du côté du joueur. Cela signifie que le joueur a raté la balle et que l'IA a marqué un point.
- `sonPing` : Ce son est joué lorsque la balle rebondit sur une raquette, que ce soit la raquette du joueur ou celle de l'IA.
- `sonVictoire` : Ce son est joué lorsque le joueur atteint le score maximum et remporte la partie. Il indique la victoire du joueur.

Ces sons ajoutent des éléments audio immersifs au jeu, fournissant des rétroactions sonores à l'utilisateur lors de différentes actions et événements du jeu.
