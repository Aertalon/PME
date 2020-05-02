import unittest
from scripts.plant import Plant
import numpy as np


class TestPlantBasic(unittest.TestCase):

    def test_has_position(self):
        """
        Tests that plant has a position
        """
        plant = Plant()
        self.assertTrue(hasattr(plant, 'pos') and np.array_equal(plant.pos, np.array([0, 0]))
)