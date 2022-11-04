
ifdef OS
	BINARY_EXTENSION = .exe
	FixPath = $(subst /,\,$1)
else
	ifeq ($(shell uname), Linux)
		BINARY_EXTENSION =
		FixPath = $1
	endif
endif

all: custom_solution standard_solution

helper.o:
	gcc -g -c helper.c -o helper.o

custom_solution: helper.o
	gcc custom_solution.c helper.o -o custom_solution$(BINARY_EXTENSION)

standard_solution:
	gcc standard_solution.c -o standard_solution$(BINARY_EXTENSION)

clean:
	rm helper.o standard_solution$(BINARY_EXTENSION) custom_solution$(BINARY_EXTENSION)
