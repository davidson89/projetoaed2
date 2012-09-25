FLAGS= -ansi -pedantic -Wall -g -efence 
CLASSES=HashTable.cpp Les.cpp main.cpp

# regra principal
all: ep1

# gera o executável
ep1:
	g++ -o ep1 ${CLASSES} 
	@echo "\n\n*****Para gerar todos os arquivos, como doxygen, digite make ep1d*****\n\n"

# make clean
clean:
	rm -f *.o ep1

ep1d:
	g++ ${FLAGS} -o ep1d: ${CLASSES}
	doxygen -g
	doxygen
