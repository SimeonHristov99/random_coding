# class Node(object):
#     def __init__(self, data):
#         self.data = data
#         self.next = None


def append(listA, listB):
    if listA is None:
        return listB

    current = listA

    while current.next is not None:
        current = current.next

    current.next = listB

    return listA
