#ifndef GUESS_H
#define GUESS_H

void guess_init(void);
void guess_count_down_or_up(int iniziale, int finale, int stampa);
void guess_print_vittoria(int moltiplicatore);
void guess_print_sconfitta(int moltiplicatore);

int guess_generate_num(int min, int max);
int guess_controlla_numero(int numero, int tentativo);


int guess_add_e_rm_punti(int tentativi_max, int num_tentativi, int hai_indovinato, int numero);
int guess_add_punti(int tentativi_max, int num_tentativi);
int guess_rm_punti(int tentativi_max, int num_tentativi);

#endif