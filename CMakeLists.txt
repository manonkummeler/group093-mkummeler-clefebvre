cmake_minimum_required(VERSION 3.10)
project(Projet element finis - ARC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Ajoute tes fichiers source ici (si on utilise une fonction, définie dans code.c, dans main.c, il faut l'ajouter aussi)
add_executable(executable_main src/main.c)


# Spécifie les options de compilation, si nécessaire
# add_compile_options(-Wall -Wextra -pedantic)