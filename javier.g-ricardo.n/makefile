all: clean
	gcc -Wall -Wpedantic -lm main.c -o main.app
	./main.app < input.txt
	gcc -Wall -Wpedantic -lm specs.c -o specs.app
	./specs.app 

clean:
	rm -rf *.app
