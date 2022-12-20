# Better one
# def likes(names):
#     match names:
#         case []: return 'no one likes this'
#         case [a]: return f'{a} likes this'
#         case [a, b]: return f'{a} and {b} like this'
#         case [a, b, c]: return f'{a}, {b} and {c} like this'
#         case [a, b, *rest]: return f'{a}, {b} and {len(rest)} others like this'

def likes(names):
    len_names = len(names)
    if len_names == 0:
        return 'no one likes this'

    if len_names == 1:
        return f'{names[0]} likes this'

    if len_names == 2:
        return f'{names[0]} and {names[1]} like this'

    if len_names == 3:
        return f'{names[0]}, {names[1]} and {names[2]} like this'

    return f'{names[0]}, {names[1]} and {len(names) - 2} others like this'
