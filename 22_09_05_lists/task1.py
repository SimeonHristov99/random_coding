class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


def remove_duplicates(head):
    current = head

    while current is not None and current.next is not None:
        if current.next.data == current.data:
            tmp = current.next
            current.next = tmp.next
            tmp.next = None
            del tmp
        else:
            current = current.next

    return head
