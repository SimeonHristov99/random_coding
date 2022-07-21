# class Tree
#   attr_accessor :val
#   attr_accessor :left
#   attr_accessor :right
# end
class Solution
    def solve(root)
        if !root
            return 0
        end

        return root.val + solve(root.left) + solve(root.right)
    end
end