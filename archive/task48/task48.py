from collections import Counter
from typing import List


def frequencySort(nums: List[int]) -> List[int]:
    return [k for (k, v) in sorted(Counter(nums).items(), key=lambda p: (p[1], -p[0])) for _ in range(v)]
