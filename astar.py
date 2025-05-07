import enum
import time
from random import randint
from enum import Enum
import math
from collections import deque
from queue import PriorityQueue

class Cell(Enum):
    EMPTY = 0,
    ROUTE = 1,
    VISITED = 2,
    WALL = 3

height = 25
width = 50

board = [[Cell.EMPTY for _ in range(width)] for _ in range(height)]
prev_board = [[Cell.EMPTY for _ in range(width)] for _ in range(height)]
start = (0, 0)
end = (width - 1, height - 1)

def clear():
    print("\033c", end="")

def hide_cursor():
    print("\033[?25l", end="")

def show_cursor():
    print("\033[?25h", end="")

def put_char(x:int, y:int, c):
    print(f"\033[{y};{x}H{c}", end="", flush=True)

def draw_board():
    for (y, row) in enumerate(board):
        for (x, cell) in enumerate(row):
            if(cell == prev_board[y][x]):
                continue
            
            prev_board[y][x] = cell

            if(cell == Cell.EMPTY):
                c = ' '
            elif(cell == Cell.WALL):
                c = '\033[31;1mO\033[0m'
            elif(cell == Cell.ROUTE):
                c = '\033[32mO\033[0m'
            else:
                c = '\033[34mO\033[0m'

            put_char(x, y, c)

def draw_walls():
    dist = [
        [0, 1],
        [1, 0],
        [1, 1],

        [-1, 0],
        [0, -1],
        [-1, -1],

        [1, -1],
        [-1, 1],
    ]

    for _ in range(150):
        global x, y
        x = randint(0, width-1)
        y = randint(0, height-1)
        d = randint(0, 7)
        n = randint(0, 6)
        for _ in range(n):
            x, y = (x + dist[d][0], y + dist[d][1])
            if(y >= height or x >= width or y < 0 or x < 0):
                continue
            board[y][x] = Cell.WALL
            # print(f"{y+i=} {x=}")
            draw_board()
        time.sleep(0.001)

def astar():
    d = [
        ([0, 1], 1.0),
        ([1, 0], 1.0),
        ([-1, 0], 1.0),
        ([0, -1], 1.0),

        ([1, 1], 1.414),
        ([-1, -1], 1.414),
        ([1, -1], 1.414),
        ([-1, 1], 1.414),
    ]

    dist = [[float(math.inf) for _ in range(width)] for _ in range(height)]
    f = [[(0, 0) for _ in range(width)] for _ in range(height)]
    short_dist = float(math.inf)

    (sx, sy) = start
    (ex, ey) = end

    dist[sy][sx] = 0
    q = PriorityQueue()

    def fdist(start, end):
        return (math.sqrt(math.pow(end[1] - start[1], 2) + math.pow(end[0] - start[0], 2)))

    q.put(
        (fdist(start, end), 
         start, 
        )
       )

    while(not q.empty()):
        cost, (x, y) = q.get()

        if(board[y][x] == Cell.WALL):
            continue

        if ((fdist((x, y), end) + dist[y][x]) > short_dist):
            continue

        if(x == ex and y == ey):
            short_dist = min(short_dist, dist[y][x])
            continue

        if (board[y][x] == Cell.VISITED):
            continue

        board[y][x] = Cell.VISITED
        draw_board()
        time.sleep(0.001)

        for dd in d:
            nx = x+dd[0][0]
            ny = y+dd[0][1]
            cost = dd[1]

            if (nx >= width or ny >= height or ny < 0 or nx < 0):
                continue

            if (dist[y][x] + cost > dist[ny][nx]):
                continue

            dist[ny][nx] = dist[y][x] + cost

            f[ny][nx] = (x, y)

            q.put(
                (fdist((nx, ny), end) + dist[y][x] + cost, 
                 (nx, ny), 
                )
               )

    if(short_dist != math.inf):
        global rx
        global ry
        rx, ry = f[ey][ex]

        while (rx != sx or ry != sy):
            board[ry][rx] = Cell.ROUTE
            draw_board()
            time.sleep(0.001)
            rx, ry = f[ry][rx]
    else:
        print("no path found")


clear()
# hide_cursor()
draw_board()
draw_walls()
astar()
draw_board()
# show_cursor()
