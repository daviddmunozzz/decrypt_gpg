import itertools

characters = "abcdefghijklmnopqrstuvwxyz" # This password has only lowercase characters

def generate_permutations(characters, length): 
    return itertools.product(characters, repeat=length)

def create_dictionary():
    dictionary = []
    for length in range(1, 5): # Range is variable
        for permutation in generate_permutations(characters, length):
            passphrase = (''.join(permutation))
            print(passphrase)
            dictionary.append(passphrase)
    with open("dictionary.txt", "w") as f:
        for item in dictionary:
            f.write("%s\n" % item)

create_dictionary()