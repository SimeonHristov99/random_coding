# Better approach
# from functools import reduce
# from itertools import cycle

# def reduce_by_rules(lst, rules):
#   rs = cycle(rules)
#   return reduce(lambda x, y: next(rs)(x, y), lst)

def reduce_by_rules(lst, rules):
    res = lst[0]
    instr_ptr = 0
    len_rules = len(rules)

    for n in lst[1:]:
        res = rules[instr_ptr](res, n)
        instr_ptr = (instr_ptr + 1) % len_rules

    return res
