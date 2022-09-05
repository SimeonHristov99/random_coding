# class Node(object):
#     def __init__(self, data):
#         self.data = data
#         self.next = None

def insert_sort(head):
    result = None

    while head is not None:
        result = sorted_insert(result, head.data)
        head = head.next

    return result
