class Solution
    def solve(rooms, target)
        for r in rooms
            if r >= target
                return r
            end
        end
        return -1
    end
end