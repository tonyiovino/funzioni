import cai

def rispondi_e_controlla(a, b, risposta_esatta):

    esatta = 0

    print(f"Quanto fa {a} per {b}? (CTRL+C per uscire)")
    risposta = int(input("Risposta: "))

    esatta = cai.check_result_and_generate_string(risposta, risposta_esatta)

    return esatta

def controlla_risposte_esatte(num_esatte, num_domande):

    percentuale = ( num_esatte / num_domande ) * 100

    print(f"Your rate is: {percentuale}%")

    if percentuale < 75: print("Please ask your instructor for extra help")

    else: print("Good Job!")

num_domande = 10
num_risposte = 0
num_esatte = 0

while (num_risposte < num_domande):
    a = cai.generate_num(0, 10)
    b = cai.generate_num(0, 10)

    risposta_esatta = a * b

    num_esatte = num_esatte + rispondi_e_controlla(a, b, risposta_esatta)
    num_risposte = num_risposte + 1

controlla_risposte_esatte(num_esatte, num_domande)