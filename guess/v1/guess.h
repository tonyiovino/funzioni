#ifndef GUESS_H
#define GUESS_H

void guess_init(void);
int guess_generate_num(int min, int max);
int guess_controlla_numero_e_restituisci(int numero, int tentativo);

#endif