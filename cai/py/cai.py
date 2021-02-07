import random

def generate_num(min, max):
    return random.randint(min, max)

def check_result_and_generate_string(risposta, risposta_esatta):

    num = generate_num(1, 4)
    esatta = 0

    if risposta == risposta_esatta:
        print_risposta_esatta(num)
        esatta = 1

    else:
        print_risposta_errata(num)

    print('\n')

    return esatta

def print_risposta_esatta(num):
    if num == 1:
        print("Very good!")
    elif num == 2:
        print("Excellent!")
    elif num == 3:
        print("Nice work!")
    elif num == 4:
        print("Keep up the good work!")
    else:
        print("Error")

def print_risposta_errata(num):
    if num == 1:
        print("No. Please try again.")
    elif num == 2:
        print("Wrong. Try once more.")
    elif num == 3:
        print("Don't give up!")
    elif num == 4:
        print("No. Keep trying.")
    else:
        print("Error")

if __name__ == '__main__':
  import doctest
  doctest.testmod()