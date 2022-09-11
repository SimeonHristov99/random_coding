def shuffle_merge(first, second):
    if first is None:
        return second

    if second is None:
        return first

    head = Node(first.data)
    cf = head
    first = first.next

    while first is not None and second is not None:
        cf.next = Node(second.data)
        cf = cf.next

        cf.next = Node(first.data)
        cf = cf.next

        first = first.next
        second = second.next

    cf.next = second if first is None else first

    return head
