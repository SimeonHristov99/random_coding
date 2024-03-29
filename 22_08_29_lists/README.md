# Tasks

## Monday

Write push() and buildOneTwoThree() functions to easily update and initialize linked lists. Try to use the push() function within your buildOneTwoThree() function.

Here's an example of push() usage:
    var chained = null
    chained = push(chained, 3)
    chained = push(chained, 2)
    chained = push(chained, 1)
    push(chained, 8) === 8 -> 1 -> 2 -> 3 -> null

The push function accepts head and data parameters, where head is either a node object or null/None/nil. Your push implementation should be able to create a new linked list/node when head is null/None/nil.

The buildOneTwoThree function should create and return a linked list with three nodes: `1 -> 2 -> 3 -> null`.

## Tuesday

Implement Length() to count the number of nodes in a linked list.

    Length(null) => 0
    Length(1 -> 2 -> 3 -> null) => 3

Implement Count() to count the occurrences of an integer in a linked list.

    Count(null, 1) => 0
    Count(1 -> 2 -> 3 -> nullptr, 1) => 1
    Count(1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 3 -> nullptr, 2) => 4

The `push()/Push()` and `buildOneTwoThree()/BuildOneTwoThree()` functions do not need to be redefined.

## Wednesday

Implement a GetNth() function that takes a linked list and an integer index and returns the node stored at the Nth index position. GetNth() uses the C numbering convention that the first node is index 0, the second is index 1, ... and so on.

So for the list 42 -> 13 -> 666, GetNth(1) should return Node(13);

    getNth(1 -> 2 -> 3 -> null, 0).data === 1
    getNth(1 -> 2 -> 3 -> null, 1).data === 2

The index should be in the range [0..length-1]. If it is not, or if the list is empty, GetNth() should throw/raise an exception.

## Thursday

Implement an InsertNth() function (insert_nth() in PHP) which can insert a new node at any index within a list.

InsertNth() is a more general version of the Push() function that we implemented in the first kata listed below. Given a list, an index 'n' in the range 0..length, and a data element, add a new node to the list so that it has the given index. InsertNth() should return the head of the list.

    insertNth(1 -> 2 -> 3 -> null, 0, 7) === 7 -> 1 -> 2 -> 3 -> null)
    insertNth(1 -> 2 -> 3 -> null, 1, 7) === 1 -> 7 -> 2 -> 3 -> null)
    insertNth(1 -> 2 -> 3 -> null, 3, 7) === 1 -> 2 -> 3 -> 7 -> null)

You must throw/raise an exception if the index is too large.

## Friday

Write a `SortedInsert()` function which inserts a node into the correct location of a pre-sorted linked list which is sorted in ascending order. `SortedInsert` takes the head of a linked list and data used to create a node as arguments. `SortedInsert()` should also return the head of the list.

    sortedInsert(1 -> 2 -> 3 -> null, 4) === 1 -> 2 -> 3 -> 4 -> null)
    sortedInsert(1 -> 7 -> 8 -> null, 5) === 1 -> 5 -> 7 -> 8 -> null)
    sortedInsert(3 -> 5 -> 9 -> null, 7) === 3 -> 5 -> 7 -> 9 -> null)

## Saturday

Write an `InsertSort()` function which rearranges nodes in a linked list so they are sorted in increasing order. You can use the `SortedInsert()` function. The `InsertSort()` function takes the head of a linked list as an argument and must return the head of the linked list.

    var list = 4 -> 3 -> 1 -> 2 -> null
    insertSort(list) === 1 -> 2 -> 3 -> 4 -> null

If the passed in head node is null or a single node, return null or the single node, respectively. You can assume that the head node will always be either `null`, a single node, or a linked list consisting of multiple nodes.

## Sunday

Write an `Append()` function which appends one linked list to another. The head of the resulting list should be returned.

    var listA = 1 -> 2 -> 3 -> null
    var listB = 4 -> 5 -> 6 -> null
    append(listA, listB) === 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null

If both `listA` and `listB` are `None`, return `None`. If one list is `None` and the other is not, simply return the `None` list.
