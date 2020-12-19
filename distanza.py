import math

#     punto1  punto2
#  x   [0]     [0]
#
#  y   [1]     [1]

def distanza(punto1, punto2):
  dx = punto1[0] - punto2[0]
  dy = punto1[1] - punto2[1]

  distanza = math.sqrt(dx**2 + dy**2)

  return distanza

def input_punto():
  x = input("Coordinata x: ")
  x = float(x)

  y = input("Coordinata y: ")
  y = float(y)

  return (x, y)

def output_punto(punto):
  print("x:", punto[0])
  print("y:", punto[1])

# main
print("Distanza tra due punti\n")

#input
print("Punto 1")
punto1 = input_punto()

print("\nPunto 2")
punto2 = input_punto()


#output
print("\nPrimo Punto")
output_punto(punto1)

print("\nSecondo Punto")
output_punto(punto2)


#assignment
distanza = distanza(punto1, punto2)

#result print
print("La distanza è:", distanza)