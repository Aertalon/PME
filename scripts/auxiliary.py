import numpy as np
import random
from scripts.environment import DIRECTIONS


def random_position(w):

    pos = np.array([0, 0])
    pos[0] = w.boundaries[0][0] + random.random() * (w.boundaries[1][0] - w.boundaries[0][0])
    pos[1] = w.boundaries[0][1] + random.random() * (w.boundaries[1][1] - w.boundaries[0][1])

    return pos


def random_direction():
    possible_dirs = [*DIRECTIONS]
    return possible_dirs[random.randint(0, len(possible_dirs) - 1)]

def distance(v1, v2):
    return sum(abs(v1-v2))