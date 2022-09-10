def front_back_split(source, front, back):
    if source is None or source.next is None:
        raise InvalidArgument('length less than 2')

    slow, fast, current = source, source, source

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

    front.data = current.data
    cf = front

    if fast is not None:
        slow = slow.next
    back.data = slow.data
    cs = back

    if current.next.next is None:
        return

    current = current.next

    while current != slow:
        cf.next = Node(current.data)
        cf = cf.next
        current = current.next

    slow = slow.next
    while slow is not None:
        cs.next = Node(slow.data)
        cs = cs.next
        slow = slow.next
