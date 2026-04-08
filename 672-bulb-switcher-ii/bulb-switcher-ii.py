class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        if presses == 0:
            return 1
        
        n = min(n, 6)
        presses = min(presses, 3)

        masks = [0, 0, 0, 0]
        for i in range(n):
            masks[0] |= (1 << i)
            if (i + 1) % 2 == 0:
                masks[1] |= (1 << i)
            if (i + 1) % 2 == 1:
                masks[2] |= (1 << i)
            if (i + 1) % 3 == 1:
                masks[3] |= (1 << i)
        
        curr_level = {0}
        
        for steps in range(presses):
            next_level = set()
            for state in curr_level:
                for mask in masks:  # change states
                    new_state = state ^ mask
                    next_level.add(new_state)
            curr_level = next_level

        return len(curr_level)