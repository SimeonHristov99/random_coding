class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


def get_nth(node, index):
    while node.next is not None and index > 0:
        node = node.next
        index -= 1

    if index != 0:
        raise IndexError('index out of range')

    return node
