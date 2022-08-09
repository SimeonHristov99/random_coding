from typing import List


def twoSum(self, nums: List[int], target: int) -> List[int]:
    diffs = {}

    for i, n in enumerate(nums):
        if diffs.get(n) is None:
            diffs[target - n] = i
        else:
            return [i, diffs[n]]

    return None
