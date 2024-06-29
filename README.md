# Rubiks_Cube_Solver_Self_Project

While learning how to incorporate graph theory into programming, I started wondering what cool things could be accomplished using these algorithms. That's when I realized the states of a Rubik's cube could be modeled as the nodes of a graph and the moves as the edges. It was challenging figuring out exactly how to get the virtual representation I needed before actually applying BFS and DFS. I ultimately chose to model the cube as a 54 character long 1D array. I then implemented the BFS and DFS algorithms. I read about this interesting algorithm that improves upon DFS and BFS in a large number of cases called IDDFS. I implemented this algorithm as well. The average solving time for these is under 20 seconds for a cube that has been shuffled 8 times.
