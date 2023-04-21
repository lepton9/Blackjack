import sys

def cardTxtFileTf(fileName):
    file = fileName

    with open(file) as f:
        content = f.readlines()

    cards = []
    card = []
    i = 0

    for line in content:
        card.append(line.replace("\n", ""))
        if (i == 5):
            cards.append(card)
            card = []
            i = 0
            continue
        i += 1

    return cards


if __name__ == "__main__":
    cards = cardTxtFileTf(sys.argv[1])
    print(cards)
