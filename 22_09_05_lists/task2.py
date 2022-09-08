class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


class Context(object):
    def __init__(self, source, dest):
        self.source = source
        self.dest = dest


def move_node(source, dest):
    if source is None:
        raise InvalidArgument("Source list empty!")

    tmp = source
    source = source.next

    tmp.next = dest
    dest = tmp

    return Context(source, dest)
