# Set compiler
CC = gcc

# set raylib src path
raylibsrc = ./dep/raylib

# Include
Include = -I${raylibsrc} -I./dep/others

# Source Files To Compile
SrcInput = renderer.c

# Source Files Output
SrcOutput = renderer.o

# Raylib Build Objects To Include
OBJS = ${raylibsrc}/core.o \
       ${raylibsrc}/shapes.o \
       ${raylibsrc}/textures.o \
       ${raylibsrc}/text.o \
       ${raylibsrc}/utils.o \
	   ${raylibsrc}/rglfw.o \
	   ${raylibsrc}/models.o \
	   ${raylibsrc}/raudio.o

# Set make command
ifeq (${OS},Windows_NT)
	makecmd = mingw32-make
else
	makecmd = make
endif

all:
	${CC} -E HopeUI.h -o ./include/HopeUI.h
	@cd ${raylibsrc} && ${makecmd} build
	${CC} -c ${SrcInput} -o ${SrcOutput} ${Include}
	ar rcs libhopeui.a ${OBJS} ${SrcOutput}
