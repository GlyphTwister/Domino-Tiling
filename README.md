# Recursive Domino Tiling

Text description:

The Recursive Domino Tiling program finds the number of different solutions to the problem of covering a board with dominos (with restrictions, such that holes cannot be covered, only one domino can occupy a given square, etc). It consists of two functions: A wrapper function and a workhorse function. 

* The wrapper function takes the dimensions of a board and two holes received by parameters. It initializes this board with holes, then calls the workhorse function with the board, its dimensions, and the number of empty squares as parameters.

* The recursive function begins by checking a base case. This measures if the number of available squares on the board remaining are equal to zero. If so, the function will return 1 as an integer representing a true solution. If this case is false, the recursive function will iterate through the board to find the first empty square. It will then try a horizontal domino placement and recurse with this placement as a parameter. Continuing, the function will attempt the same with a vertical placement. A variable representing the total will be returned at the end of the placements. Once all the recursive calls have concluded, the wrapper function will return the number of solutions to a given board problem.


flowchart LR
    subgraph Wrapper Function {
        A(Initialize board with holes) --> B(Call recursive function)
        B --> C(Return result)
    }
    subgraph Recursive Function {
        C(Check base case) --> D(Iterate through board)
        D --> E(Try horizontal placement)
        D --> F(Try vertical placement)
        E --> G(Recurse) --> H(Restore board) --> C
        F --> G --> H --> C
    }