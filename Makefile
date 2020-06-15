  # the compiler: gcc for C program, define as g++ for C++
  CC = gcc 

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:

	#TARGET = set_bits_in_array
	#TARGET = reverse_bit
	#TARGET = duplicates_of_array
	#TARGET = SNOB
	#TARGET = parity_lookuptable
	TARGET = m_into_n
	
  all: $(TARGET).c
	$(CC) $(CFLAGS) -o exe $(TARGET).c

  clean: 
	$(RM) exe
