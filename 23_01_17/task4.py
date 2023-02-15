# Better one
# def how_much_i_love_you(nb_petals):
#     return ["not at all", "I love you", "a little", "a lot", "passionately", "madly"][nb_petals % 6]

outputs = [
    "I love you",
    "a little",
    "a lot",
    "passionately",
    "madly",
    "not at all",
]

def how_much_i_love_you(nb_petals):
    return outputs[(nb_petals - 1) % len(outputs)]