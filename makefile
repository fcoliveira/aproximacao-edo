CC = gcc
CFLAGS = -Wall -std=c99 -pedantic
DEPS = dados_entrada.h euler_explicito.h euler_implicito.h rk_44.h sol_analitica.h funcoes.h
OBJ = dados_entrada.o euler_explicito.o euler_implicito.o rk_44.o sol_analitica.o main.o funcoes.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

aproxima_edo: $(OBJ)
	gcc $(CFLAGS) -o $@ $^
	
