all:Sprint3

Sprint3: main.o help.o allo.o free_mem.o display.o write.o xor_inv.o rand_gen.o verify_pattern.o exit_app.o clear.o
	gcc main.o help.o allo.o free_mem.o display.o write.o xor_inv.o rand_gen.o verify_pattern.o exit_app.o clear.o -o Sprint3

main.o: main.c
	gcc -c main.c

help.o: help.c
	gcc -c help.c

allo.o: allo.c
	gcc -c allo.c

free_mem.o: free_mem.c
	gcc -c free_mem.c

display.o: display.c
	gcc -c display.c

write.o: write.c
	gcc -c write.c

xor_inv.o: xor_inv.c
	gcc -c xor_inv.c

rand_gen.o: rand_gen.c
	gcc -c rand_gen.c

verify_pattern.o: verify_pattern.c
	gcc -c verify_pattern.c

exit_app.o: exit_app.c
	gcc -c exit_app.c

clean:
	rm -rf *o Sprint3

clear.o: clear.c
	gcc -c clear.c
