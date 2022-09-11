# Tasks

## Monday

Write a `RemoveDuplicates()` function which takes a list sorted in increasing order and deletes any duplicate nodes from the list. Ideally, the list should only be traversed once. The head of the resulting list should be returned.

```js
var list = 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> null
removeDuplicates(list) === 1 -> 2 -> 3 -> 4 -> 5 -> null
```

If the passed in list is `null`, simply return `null`.

> **Note**: Your solution is expected to work on long lists. Recursive solutions may fail due to stack size limitations.

## Tuesday

Write a `MoveNode()` function which takes the node from the front of the source list and moves it to the front of the destintation list. You should throw an error when the source list is empty. For simplicity, we use a `Context` object to store and return the state of the two linked lists.

```text
source = 1 -> 2 -> 3 -> None
dest = 4 -> 5 -> 6 -> None
move_node(source, dest).source == 2 -> 3 -> None
move_node(source, dest).dest == 1 -> 4 -> 5 -> 6 -> None
```

## Wednesday

Write an `AlternatingSplit()` function that takes one list and divides up its nodes to make two smaller lists. The sublists should be made from alternating elements in the original list. So if the original list is `a -> b -> a -> b -> a -> null` then one sublist should be `a -> a -> a -> null` and the other should be `b -> b -> null`.

```text
list = 1 -> 2 -> 3 -> 4 -> 5 -> None
alternating_split(list).first == 1 -> 3 -> 5 -> None
alternating_split(list).second == 2 -> 4 -> None
```

For simplicity, we use a `Context` object to store and return the state of the two linked lists. A `Context` object containing the two mutated lists should be returned by `AlternatingSplit()`.

If the passed in head node is `None` or a single node, throw an error.

## Thursday

Write a `FrontBackSplit()` function that takes one list and splits it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra element should go in the front list. For example, `FrontBackSplit()` on the list `2 -> 3 -> 5 -> 7 -> 11 -> null` should yield the two lists `2 -> 3 -> 5 -> null` and `7 -> 11 -> null`.

```js
var source = 1 -> 3 -> 7 -> 8 -> 11 -> 12 -> 14 -> null
var front = new Node()
var back = new Node()
frontBackSplit(source, front, back)
front === 1 -> 3 -> 7 -> 8 -> null
back === 11 -> 12 -> 14 -> null
```

Throw an error if any of the arguments to `FrontBackSplit` are `null` or if the source list has `< 2` nodes.

## Friday

Write a `ShuffleMerge()` function that takes two lists and merges their nodes together to make one list, taking nodes alternately between the two lists. So `ShuffleMerge()` with `1 -> 2 -> 3 -> null` and `7 -> 13 -> 1 -> null` should yield `1 -> 7 -> 2 -> 13 -> 3 -> 1 -> null`. If either list runs out, all the nodes should be taken from the other list. `ShuffleMerge()` should return the new list. The solution depends on being able to move nodes to the end of a list.

```js
var first = 3 -> 2 -> 8 -> null
var second = 5 -> 6 -> 1 -> 9 -> 11 -> null
shuffleMerge(first, second) === 3 -> 5 -> 2 -> 6 -> 8 -> 1 -> 9 -> 11 -> null
```
