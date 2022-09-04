"""
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None
"""


def sorted_insert(head, data):
    if head is None or data < head.data:
        new_head = Node(data)
        new_head.next = head
        return new_head

    current = head

    while current.next is not None and current.next.data < data:
        current = current.next

    if current.next is None:
        current.next = Node(data)
        return head

    new_head = Node(data)
    new_head.next = current.next
    current.next = new_head

    return head
