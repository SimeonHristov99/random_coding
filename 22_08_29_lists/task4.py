class Node(object):
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


def insert_nth(head, index, data):
    if index == 0:
        head = Node(data, head)
        return head

    current = head

    while current is not None and index > 1:
        current = current.next
        index -= 1

    if current is None and index != 1:
        raise IndexError('index out of bounds')

    current.next = Node(data, current.next)

    return head
