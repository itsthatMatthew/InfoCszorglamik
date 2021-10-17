# sourcefile to compile
OBJS = mertanihely.c

# output file
OBJO = mertanihely.exe

# compiler
CC = gcc

# includes (header files)
INCLUDE_PATHS = -IC:\mingw_dev_lib\include\SDL2

# libraries
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib

# additional compilation options
COMPILER_FLAGS = -w -Wl,-subsystem,windows

# libraries to link against
LINKER_FLAGS = -lmingw32 -lSDL2_ttf -lSDL2main -lSDL2

all : $(OBJS)
	$(CC) $(OBJS) -o $(OBJO) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)
