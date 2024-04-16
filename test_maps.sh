# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_maps.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:06:39 by ykifadji          #+#    #+#              #
#    Updated: 2024/04/16 10:55:00 by ykifadji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
DEF='\033[0m'
BOLD='\033[1m'
UNDERLINE='\033[4m'
RED='\033[31;2m'
BLACK='\033[38;5;238m'
BLUE='\033[38;5;153m'
GREEN='\033[38;5;48m'
YELLOW='\033[38;5;226m'
ORANGE='\033[38;5;202m'
PINK='\033[38;5;198m'
PURPLE='\033[38;5;147m'
UP=UP='\033[A'

#!/bin/bash

# Chemin de l'exécutable
EXECUTABLE="./cub3D"

# Dossier contenant les maps invalides
DOSSIER_INVALIDE="./invalid"

# Parcours de toutes les maps avec l'extension .cub dans le dossier invalide
for MAP in ${DOSSIER_INVALIDE}/*.cub; do
    # Affichage du nom de la map en cours de test
    echo "${BOLD}${BLUE}Test de la map :${DEF} ${UNDERLINE}$MAP${DEF}"

    # Test de la map avec l'exécutable
    ${EXECUTABLE} $MAP

    # Vérification du code de retour de l'exécutable
    if [ $? -eq 0 ]; then
        echo "${BOLD}${GREEN}La map $MAP a réussi le test.${DEF}"
    else
        echo "${BOLD}${RED}La map $MAP a échoué le test.${DEF}"
    fi
done