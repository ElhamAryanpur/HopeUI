set /p file=Type The File Name To Compile -

gcc %file%.c -o %file%.exe -I./include -L./bin -lraylib
mv %file%.exe ./bin