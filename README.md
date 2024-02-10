# STDISCM-MCO1-Particles_CPP

## Build from source
### Linux / WSL
1. [Install SFML first if haven't already](https://www.sfml-dev.org/tutorials/2.6/start-linux.php)
```
sudo apt-get install libsfml-dev
```
2. Compile
```
g++ -c main.cpp
```
3. [Link](https://www.sfml-dev.org/tutorials/2.6/start-linux.php)
```
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
```
4. Run
```
./sfml-app
```
