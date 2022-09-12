class Node(object):
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


def sorted_merge(first, second):
    if not (first and second):
        return first or second
    if first.data < second.data:
        return Node(first.data, sorted_merge(first.next, second))
    return Node(second.data, sorted_merge(first, second.next))
