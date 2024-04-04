# Informations utiles à se partager # 
(on pourra mettre les éléments utiles de ce document dans le README)


## README
Il faudra le changer en .txt (mais après car c'est un format moins lisible)

## build  
Pour créer/modifier le build, il faut utiliser la commande cmake : "cmake -S . -B build"
Si on ajoute un nouveau fichier source à notre projet (qui n'est pas lié au **main.c** via un include), 
on devra l'inclure dans le fichier **CMakeLists.txt** en utilisant la fonction *add_executable*. 
Ensuite, on devra régénérer le build en exécutant à nouveau la commande cmake ci-dessus.


## structure 
structures des includes (liens entres les fichiers) :

                main.c
                  |       test.c
                  v         |
                code.c  < -- 
                  |
                  v
               struct.h
                  |
                  v
           les librairies


## compiler
Pour compiler le projet, faire les commandes suivantes : 
cd build
make

Pour executer l'executable, faire la commande suivante : 
./executable_main 


## Makefile
Un Mafefile s'est crée tout seul, pratique !
Demandons aux assistants s'il en faut un ou non, et si oui s'il faut l'ajuster spécifiquement à notre code ou non. 