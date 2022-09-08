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

