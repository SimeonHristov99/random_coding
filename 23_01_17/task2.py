# Better approach
# def same_structure_as(original,other):
#     if isinstance(original, list) and isinstance(other, list) and len(original) == len(other):
#         for o1, o2 in zip(original, other):
#             if not same_structure_as(o1, o2): return False
#         else: return True
#     else: return not isinstance(original, list) and not isinstance(other, list)

def same_structure_as(original, other):
    t1 = type(original)
    t2 = type(other)

    if t1 != t2 \
        or t1 == t2 == list \
            and len(original) != len(other):
        return False

    for l1, l2 in zip(original, other):
        t1 = type(l1)
        t2 = type(l2)

        if t1 != t2 and (t1 == list or t2 == list):
            return False

        if t1 == list:
            return len(l1) == len(l2) and same_structure_as(l1, l2)

    return True
