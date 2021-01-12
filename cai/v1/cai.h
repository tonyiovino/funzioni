#ifndef CAI_H
#define CAI_H

void cai_init(void);
int cai_generate_num(int min, int max);
void cai_generate_string(int risposta, int risposta_esatta);
void cai_risposta_esatta(int num);
void cai_risposta_errata(int num);

#endif