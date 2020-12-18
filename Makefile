CC := g++ -Wall -Werror
FLAGS := -std=c99
FLAG := -std=c11

.PHONY: all clean install uninstall rebuild

all: bin/LiteSH

#bin/LiteSH: builds/main.o builds/LiteSH.o builds/commands.o builds/main1.o
#	$(CC) builds/main.o builds/LiteSH.o builds/main1.o builds/commands.o -o bin/LiteSH

bin/LiteSH: builds/main.o builds/LiteSH.o builds/commands.o builds/main1.o
	$(CC) builds/main.o builds/LiteSH.o builds/main1.o builds/commands.o -I./home/misha/Labs/CoursWorkOS/libs/libinfo.so -ldl -o bin/LiteSH

builds/main.o: src/client/main.cpp
	$(CC) -c src/client/main.cpp -o builds/main.o

builds/LiteSH.o: src/client/LiteSH.cpp
	$(CC) -c src/client/LiteSH.cpp -o builds/LiteSH.o

builds/main1.o: src/client/main1.cpp
	$(CC) -c src/client/main1.cpp -o builds/main1.o

builds/commands.o: src/client/commands.cpp
	$(CC) -c src/client/commands.cpp -o builds/commands.o

clean:
	find -name "*.o" -exec rm -rf {} +
	rm -rf ./bin/LiteSH

install:
	sudo cp ./bin/proc /usr/bin/LiteSH

uninstall:
	sudo rm -f /usr/bin/LiteSH

rebuild: clean all