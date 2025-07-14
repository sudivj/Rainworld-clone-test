EXEC=GAME

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLACK='\e[30m'
WHITE_BG='\e[47m'
RESET="\e[0m"
ERR=

echo -e "${BLACK}${WHITE_BG}Compiling files...${RESET}"

make
if [ "$1" == "debug" ]; then
    gdb $EXEC
else
    ./$EXEC
fi
