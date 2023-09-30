# Un idraulico chiede € 40,00 per un'ora di lavoro, più il costo del materiale,
# con un minimo di € 100,00 per ogni lavoro. Scrivere un programma che, dati in
# input due interi rappresentanti rispettivamente il costo del materiale e il
# numero di ore lavorative, determini la spesa totale, facendola ammontare al
# limite minimo quando previsto.

materiale = int(input())
ore = int(input())
TARIFFA_ORARIA = 40


tot = materiale + ore * TARIFFA_ORARIA

if tot < 100:
    print(100, end="")
else:
    print(tot, end="")
