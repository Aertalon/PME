import numpy as np
from scripts.environment import World, DIRECTIONS, SAMPLE_TIME
from scripts.brain import Brain
from scripts.sense import Senses
from scripts.actions import Decision

HUNGER_DECREASE_RATE = {
    'standard': 1 / (7 * 24 * SAMPLE_TIME),
    'movement': 1 / (7 * 24 * SAMPLE_TIME)}

MAX_HEALTH = 1

class Human:

    def __init__(self, name='Mullard', pos=np.array([0, 0])):

        self.name = name

        self.health = MAX_HEALTH
        self.hunger = 0

        self.pos = pos

        self.brain = Brain()
        self.senses = Senses()

        self.perception = None
        self.decision = Decision()

        self.storage = []

    def give_status(self):

        description = """
Name: {name}
==> Position: ({pos})
==> Hunger level: {hunger}. Health level: {health}
==> Perceives: {perceptions}""".format(
            name=self.name,
            pos=self.pos,
            hunger=self.hunger,
            health=self.health,
            perceptions=self.senses.get_status())
        return description

    def perceive(self, world):
        """
        Perceives the world through senses
        :param world: the current world
        :return: []
        """

        self.perception = self.senses.perceive(world, self.pos)

    def decide(self):
        """
        Decides the next course of action based on perception
        :param: []
        :return: []
        """

        self.decision = self.brain.update(self.perception)

    def act(self):
        """
        Acts on the basis of the current basic action and update state
        """

        if (self.decision.basic_action and
                self.decision.basic_action.get_type() == 'Movement'):
            import pdb; pdb.set_trace()
            self.pos = self.pos + DIRECTIONS[self.decision.basic_action.direction]
            self.hunger = self.hunger + HUNGER_DECREASE_RATE['movement']

        self.hunger = self.hunger + HUNGER_DECREASE_RATE['standard']
        self.health = self.health - self.hunger






