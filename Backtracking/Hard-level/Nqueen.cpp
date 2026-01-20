def solve_n_queens(n):
    pos = [-1] * n   # pos[row] = column of queen in that row

    def is_safe(row, col):
        for prev_row in range(row):
            # same column
            if pos[prev_row] == col:
                return False
            # diagonal check
            if abs(pos[prev_row] - col) == abs(prev_row - row):
                return False
        return True

    def backtrack(row):
        # base case: all queens placed
        if row == n:
            print(pos)   # one valid solution
            return

        for col in range(n):
            if is_safe(row, col):
                pos[row] = col          # PLACE queen
                backtrack(row + 1)      # GO deeper
                pos[row] = -1           # REMOVE queen (BACKTRACK)

    backtrack(0)

