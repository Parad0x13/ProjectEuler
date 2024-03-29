from Euler.Solution import Solution
import Euler.Math as EM

from resources.SudokuSolver import Sudoku

def logic():
	# Grab the grids provided by ProjectEuler and format them for my SudokuSolver
	grids = open("./resources/p096_sudoku.txt").readlines()
	everything = ""
	for line in grids:
		if "Grid" in line: continue
		everything += line.rstrip()
	patterns = [everything[i:i+9*9] for i in range(0, len(everything), 9*9)]

	# Solve the puzzles and account for the solutions
	total = 0
	for pattern in patterns:
		game = Sudoku()
		game.board.setPattern(pattern)
		solution = game.solve()
		total += int(solution[:3])
		print(solution)
	print(total)
	# 25392

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
