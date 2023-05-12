# Pong


## Comment installer ?

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


