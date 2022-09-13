class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None


def merge_sort(list):
    if not list or list and not list.next:
        return list

    front = Node()
    back = Node()

    front_back_split(list, front, back)

    front_sorted = merge_sort(front)
    back_sorted = merge_sort(back)

    return sorted_merge(front_sorted, back_sorted)
