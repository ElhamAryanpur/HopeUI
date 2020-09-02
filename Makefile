# Set the platform
#
# Could be:
#
# Windows
# Unix
#
Platform = ${PLATFORM}

# Set build type
Build = ${BUILD}

# Set the file
File = ${FILE}

# Set project name
Name = ${NAME}

# Set compiler
CC = gcc

# Flags
Flags = -lopengl32 -lgdi32
WinFlags = -lopengl32 -lgdi32 -lwinmm

# Include
Include = -I./dep/raylib/src -I./HopeUI

# Set the raylib source path
raylibsrc = cd dep && cd raylib && cd src

# set back to root from raylib
raylibexit = cd .. && cd .. && cd ..

# set raylib src path
rsp = ./dep/raylib/src

ifeq (${Platform},Windows)
	ifeq (${Build},Init)
		makecmd = mingw32-make
		command = ${CC} ${File} -o ${Name}.exe ${rsp}/*.o ${Include} ${rsp}/libraylib.a ${WinFlags}
	else
		makecmd = echo building...
		command = ${CC} ${File} -o ${Name}.exe ${rsp}/*.o ${Include} ${rsp}/libraylib.a ${WinFlags}
	endif
else
	ifeq (${Build},Init)
		makecmd = make
		command = ${CC} ${File} -o ${Name} ${rsp}/*.o ${Include} ${rsp}/libraylib.a ${Flags}
	else
		makecmd = echo building...
		command = ${CC} ${File} -o ${Name} ${rsp}/*.o ${Include} ${rsp}/libraylib.a ${Flags}
	endif
endif

all:
	${raylibsrc}
	echo building
	${makecmd}
	echo building done
	${raylibexit}
	${command}

build:
	${raylibsrc}
	${makecmd}
	${raylibexit}