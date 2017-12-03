#!/usr/bin/env python3

def solve(hand1, hand2):
    a = True
    acheat = False
    bcheat = False
    for i in range(5):
        if hand1[i][0] == hand2[i][0]:
            a = (hand1[i][1] > hand2[i][1])
        else:
            for j in range(i+1, 5):
                if     a and hand1[i][0] == hand2[j][0]:
                    bcheat = True
                if not a and hand2[i][0] == hand1[j][0]:
                    acheat = True
    return (a, acheat, bcheat)

if __name__ == "__main__":
    hand1 = [None] * 5
    hand2 = [None] * 5
    for i in range(5):
        su, nu = input().split()
        hand1[i] = (su, int(nu))

    for i in range(5):
        su, nu = input().split()
        hand2[i] = (su, int(nu))

    awin, acheat, bcheat = solve(hand1, hand2)

    print('A' if awin else 'B')
    if acheat and bcheat:
        print("A och B fuskar")
    elif acheat:
        print("A fuskar")
    elif bcheat:
        print("B fuskar")
