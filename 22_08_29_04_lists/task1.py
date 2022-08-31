class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


def push(head, data):
    new_head = Node(data)
    new_head.next = head
    return new_head


def build_one_two_three():
    head = push(None, 3)
    head = push(head, 2)
    head = push(head, 1)
    return head
