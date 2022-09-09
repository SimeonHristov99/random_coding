class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Context(object):
    def __init__(self, first, second):
        self.first = first
        self.second = second


def alternating_split(head):
    if head is None or head.next is None:
        raise InvalidArgument('less than 2 nodes present')

    cf = head
    first = Node(cf.data)
    cff = first

    cs = head.next
    second = Node(cs.data)
    css = second

    while cf.next is not None and cf.next.next is not None:
        cf = cf.next.next
        cff.next = Node(cf.data)
        cff = cff.next

    while cs.next is not None and cs.next.next is not None:
        cs = cs.next.next
        css.next = Node(cs.data)
        css = css.next

    return Context(first, second)
