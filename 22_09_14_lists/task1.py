class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None


def sorted_intersect(first, second):
    if not (first and second):
        return None

    result = Node(42)
    current = result

    while first and second:
        if first.data < second.data:
            first = first.next
        elif first.data > second.data:
            second = second.next
        elif current.data == first.data:
            first = first.next
            second = second.next
        else:
            current.next = Node(first.data)
            current = current.next
            first = first.next
            second = second.next

    result = result.next
    return result
