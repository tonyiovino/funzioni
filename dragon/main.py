import dragon

play = ''
punti = 0

while play == 'y' or play != 'n':
	dragon.init_print()

	scelta = dragon.scegli_caverna()

	punti = dragon.esplora_caverna(scelta, punti)

	print(f"Points: {punti}\n")

	play = input("Do you want play again? (y or n): ")

	if play == 'y':
		print("Good Luck!\n")
	elif play == 'n':
		print("Good Bye!\n")
		break