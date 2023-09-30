almenoDueElementiConsecutivi = False

prec = ""
String = input()
while String != "*":
    if prec == String:
        almenoDueElementiConsecutivi = True
    prec = String
    String = input()

if almenoDueElementiConsecutivi:
    print("SI", end="")
else:
    print("NO", end="")
