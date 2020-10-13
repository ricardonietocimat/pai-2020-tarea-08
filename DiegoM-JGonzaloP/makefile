all: clean main specs

main: 
	gcc -g -Wall -Wpedantic -lm main.c -o main.app
	./main.app < input.txt > output.tmp
	diff --side-by-side --report-identical-files output.txt output.tmp
	
	./main.app < input2.txt > output2.tmp
	diff --side-by-side --report-identical-files output2.txt output2.tmp
specs:
	gcc -g -Wall -Wpedantic -lm specs.c -o specs.app
	./specs.app 
	gcc -g -Wall -Wpedantic -lm specsApp.c -o specsapp.app
	./specsapp.app 
clean:
	rm -rf *.app *.tmp
