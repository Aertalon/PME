import unittest
from scripts.human import Human, HUNGER_DECREASE_RATE, MAX_HEALTH
from scripts.plant import Plant
from scripts.actions import Decision, BasicMovement, BasicEat
from scripts.environment import World
import numpy as np


class TestHumanBasic(unittest.TestCase):

    def test_has_health(self):
        """
        Tests that human agent has health
        """
        human = Human()
        self.assertTrue(
            hasattr(human, 'health') and
            human.health == MAX_HEALTH)

    def test_has_hunger(self):
        """
        Tests that human agent has hunger
        """
        human = Human()
        self.assertTrue(
            hasattr(human, 'hunger') and
            human.hunger == 0)

    def test_has_action(self):
        """
        Tests that human agent has action
        """
        human = Human()
        self.assertTrue(
            hasattr(human, 'decision') and
            human.decision.basic_action is None and
            human.decision.action is None)

    def test_has_name(self):
        """
        Tests that human agent has a name (customizable)
        """
        human = Human()
        self.assertTrue(
            hasattr(human, 'name') and
            human.name == 'Mullard')
        human = Human(name='Peking')
        self.assertTrue(
            hasattr(human, 'name') and
            human.name == 'Peking')

    def test_hunger_increases(self):
        """
        Tests that hunger increases in human agents and that consequently heath decreases
        """

        human = Human()
        hunger = np.zeros(3)
        health = np.zeros(3)

        hunger[0] = human.hunger
        health[0] = human.health

        human.decision = Decision()
        human.act()

        hunger[1] = human.hunger
        health[1] = human.health

        human.decision.basic_action = BasicMovement('N')
        human.act()

        hunger[2] = human.hunger
        health[2] = human.health

        self.assertEqual(hunger[1], hunger[0] + HUNGER_DECREASE_RATE['standard'])
        self.assertEqual(health[1], health[0] - hunger[1])
        self.assertEqual(hunger[2], hunger[1] + HUNGER_DECREASE_RATE['standard'] +
                         HUNGER_DECREASE_RATE['movement'])
        self.assertEqual(health[2], health[1] - hunger[2])

    def test_eat_plant(self):
        """Tests that if a human is over a plant, they has the option of eating it.
        Eating decreases hunger by a certain amount"""

        world = World()
        plant = Plant(pos=np.array([0, 0]))
        human = Human(pos=np.array([0, 0]))

        world.add_human(human)
        world.add_plant(plant)

        human.decision.basic_action = BasicEat(edible=plant)

