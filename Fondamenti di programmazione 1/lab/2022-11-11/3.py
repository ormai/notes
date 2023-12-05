from random import randint

operando1 = randint(0, 9)
operando2 = randint(0, 9)

operatoreIndx = randint(0, 3)
operatore = ""
rispostaCorretta = ""
rispostePositive = [
    "Bravo!", "Eccellente!", "Continua così!",
    "Ottimo lavoro!"
]
risposteNegative = [
    "No, riprova!",
    "Sbagliato. Prova ancora!",
    "Non ti arrendere, riprova!",
    "Niente da fare, Prova ancora!"
]

if operatoreIndx == 0:
    operatore = '+'
    rispostaCorretta = operando1 + operando2
elif operatoreIndx == 1:
    operatore = '-'
    rispostaCorretta = operando1 - operando2
elif operatoreIndx == 2:
    operatore = '*'
    rispostaCorretta = operando1 * operando2
else:
    operatore = '/'
    rispostaCorretta = operando1 * operando2

userInput = input("Quanto fa %d%s%d? " % (operando1, operatore, operando2))

if float(userInput) == rispostaCorretta:
    print(rispostePositive[randint(1, 3)])
else:
    print(risposteNegative[randint(1, 3)])
