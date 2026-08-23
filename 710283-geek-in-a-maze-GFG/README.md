# [Geek in a Maze](https://www.geeksforgeeks.org/problems/geek-in-a-maze--170637/1?_gl=1*166jm0k*_up*MQ..*_gs*MQ..&gclid=CjwKCAjwtKrUBhAhEiwAr77ZoopsoilcWabrhvfNzySVDcsf6itekB-Ynpcy_SvT7rhLfB9mY9yX2hoCuhQQAvD_BwE&gbraid=0AAAAAC9yBkDXi1PAnrYNXB1H9RNrcfGxU)
## Hard
Given a maze mat[][] of size n × m, where each cell is either:

'.' representing an empty cell, or
'#' representing an obstacle.

Find the number of distinct empty cells that Geek can visit starting from the cell (r, c). 

Geek can move up, down, left, or right to an adjacent non-obstacle cell inside the maze.
On any path, Geek can make at most u upward moves and d downward moves.
There is no limit on the number of left or right moves. 
If the starting cell is an obstacle, return 0.

Note :&nbsp;&nbsp;There can be multiple paths starting from [r, c].
Examples:
Input: r = 1, c = 0, u = 1, d = 1, mat = [['.', '.', '.'], ['.', '#', '.'], ['#', '.', '.']]
Output: 5
Explanation: Geek starts from (1, 0) and follows the path (1,0)-&gt;(0,0)-&gt;(0,1)-&gt;(0,2)-&gt;(1,2). The cells (1,1) and (2,0) are obstacles, so they cannot be visited. Hence, Geek can visit 5 distinct empty cells. 
Input: r = 2, c = 1, u = 2, d = 2, mat = [['.', '.', '.'], ['.', '#', '.'], ['.', '.', '.']]
Output: 8
Explanation: Geek starts from (2, 1) and follows the path (2,1)-&gt;(2,2)-&gt;(1,2)-&gt;(0,2)-&gt;(0,1)-&gt;(0,0)-&gt;(1,0)-&gt;(2,0). The cell (1,1) is an obstacle, so it cannot be visited. Hence, Geek can visit all 8 empty cells.
Input: r = 2, c = 1, u = 1, d = 0, mat = [['.', '.', '.'], ['.', '#', '.'], ['.', '.', '.']]
Output: 5
Explanation: The paths followed are (2, 1)-&gt;(2, 0)-&gt;(1, 0) and (2, 1)-&gt;(2, 2)-&gt;(1, 2)
