BUILD_FOLDER=build

GREEN='\033[0;32m'
RESET="\e[0m"
ERR=

echo -e "${RESET}Compiling object files"

check_for_errors () {
    if [ ! -z "$1" ]; then
        echo
        exit 0
    fi
}

if [ ! -d "$BUILD_FOLDER" ]; then
    ERR=$(mkdir "$BUILD_FOLDER")
    check_for_errors $ERR
fi

if [ ! -d "$BUILD_FOLDER/obj" ]; then
    ERR=$(mkdir "$BUILD_FOLDER/obj")
    check_for_errors $ERR
fi


if [[ ! -z $(ls -d */ 2>errors) ]]; then
    for foldername in src/*/; do
        if [[ ! -z $(ls $foldername/*.cpp 2>errors) ]]; then
            echo -e "${RESET}- Compiling object files in $foldername/"
            for filename in $foldername*.cpp; do
                echo -n -e "${RESET}- - compiling $filename... "
                FILENAME=$(echo $filename | rev | cut -d"/" -f1 | rev)
                ERR=$(g++ -c "$filename" -o build/obj/$FILENAME.a)
                check_for_errors $ERR
                echo -e "${GREEN}done"
                ((i++))
            done
        fi
    done
fi

echo -e "${RESET}- Compiling object files in src/"

for filename in src/*.cpp; do
    echo -n -e "${RESET}- - compiling $filename... "
    FILENAME=$(echo $filename | rev | cut -d"/" -f1 | rev)
    ERR=$(g++ -c "$filename" -o build/obj/$FILENAME.a)
    check_for_errors $ERR
    echo -e "${GREEN}done"
    ((i++))
done

ERR=$(cd $BUILD_FOLDER)
check_for_errors $ERR

echo -n -e "${RESET}Combining object files..."
ERR=$(ar cr build/libs.o build/obj/*.a)
check_for_errors $ERR
echo -e "${GREEN}done"
echo -n -e "${RESET}Compiling game... "
ERR=$(g++ main.cpp -lSDL2main -lSDL2 -lSDL2_image -lSDL2_gfx -lm build/libs.o -o build/main)
check_for_errors $ERR
echo -e "${GREEN}done"
echo -e "${RESET}Running game... "
ERR=$(./build/main)
check_for_errors $ERR
echo "exited"