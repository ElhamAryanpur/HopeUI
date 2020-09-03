# Set the file
File = ${FILE}

# Set project name
Name = ${NAME}

# Set compiler
CC = gcc

# Flags
Flags = -lopengl32 -lgdi32

# Include
Include = -I./dep/raylib/src -I./HopeUI

# set back to root from raylib
raylibexit = ../../../

# set raylib src path
raylibsrc = ./dep/raylib/src

# Set make command
ifeq (${OS},Windows_NT)
	makecmd = mingw32-make
else
	makecmd = make
endif

# Set commands
ifeq (${OS},Windows_NT)
	Flags += -lwinmm
	command = ${CC} ${File} -o ${Name}.exe ${Include} ${raylibsrc}/libraylib.a ${Flags}
else
	command = ${CC} ${File} -o ${Name} ${Include} ${raylibsrc}/libraylib.a ${Flags}
endif

compile:
	${command}

build:
	cd ${raylibsrc} && ${makecmd}
