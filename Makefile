  # the compiler: gcc for C program, define as g++ for C++
  CC = gcc 

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:

   #TARGET = hash_table/double_hashing_technique
	TARGET = hello
	
  all: $(TARGET).c
	$(CC) $(CFLAGS) -o exe $(TARGET).c

  clean: 
	$(RM) exe
