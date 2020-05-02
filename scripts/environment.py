import numpy as np

DIRECTIONS = {
    'N': np.array([1, 0]),
    'S': np.array([-1, 0]),
    'W': np.array([0, -1]),
    'E': np.array([0, 1])}

SAMPLE_TIME = 1  # 1 sample = 1 hour


class World:

    def __init__(self):
        self.humans = []
        self.plants = []
        self.boundaries = np.array([
                [-100, 100],
                [-100, 100]])

    def add_human(self, h):
        self.humans.append(h)

    def add_plant(self, p):
        self.plants.append(p)

    def describe(self):
        for idx in range(len(self.humans)):
            h = self.humans[idx]
            description = h.give_status()
            print(description)

    def update(self):
        for idx in range(len(self.humans)):
            h = self.humans[idx]
            h.perceive(self)
            h.act()
            h.update()

        self.describe()

