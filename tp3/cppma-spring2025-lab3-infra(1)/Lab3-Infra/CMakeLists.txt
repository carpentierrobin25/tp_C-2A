cmake_minimum_required(VERSION 3.10)
project(MonProjet)

# 1. Standard C++
set(CMAKE_CXX_STANDARD 17)

# 2. Dossier de sortie pour l'exécutable (dans le dossier bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# 3. Indiquer où se trouvent les fichiers .hpp
# Cela permet de faire #include "mon_fichier.hpp" sans donner le chemin complet
include_directories(include)

# 4. Créer l'exécutable avec les fichiers .cxx
# (Ajoute ici tous tes fichiers .cxx séparés par des espaces)
add_executable(Simu
    src/main.cxx 
    src/Univers.cxx
    src/Particule.cxx
    src/Vecteur.cxx

)
