import random
import time

def init_print():
	print("""You are in a land full of dragons. In front of you, you see two caves.
In one cave, the dragon is friendly and will share his treasure with you.
The other dragon is greedy and hungry, and will eat you on sight.\n""")

def scegli_caverna():
	scelta = 0
	while scelta != 1 and scelta != 2:
		scelta = int(input("Which cave will you go into? (1 or 2): "))

	return scelta

def esplora_caverna(caverna, punti):
	print("You approach the cave...")
	time.sleep(1)
	print("It is dark and spooky...")
	time.sleep(1)
	print("A large dragon jumps out in front of you! He opens his jaws and...\n")
	time.sleep(1)

	if caverna == random.randint(1, 2):
		print("Gives you his treasure!")

		return punti + 10
	else:
		print("Gobbles you down in one bite!")

		return punti - 8

if __name__ == '__main__':
	import doctest
	doctest.testmod()
