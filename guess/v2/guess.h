#ifndef GUESS_H
#define GUESS_H

void guess_init(void);
int guess_generate_num(int min, int max);
int guess_controlla_numero_e_restituisci(int numero, int tentativo, int num_tentativi);
void count_down_or_up(int iniziale, int finale);
int add_punti(int tentativi_max, int num_tentativi);
int rm_punti(int tentativi_max, int num_tentativi);

#endif