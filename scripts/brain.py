from scripts.actions import BasicMovement
from scripts.actions import Decision


class Brain:

    def __init__(self):
        self.cerebellum = Cerebellum()
        self.frontal_lobe = FrontalLobe()
        self.memory = []
        self.action_tree = []

        self.decision = Decision(
                    basic_action=None,
                    action=None)

    def update(self, perception):
        next_action = self.frontal_lobe.decide_action(
            perception, self.memory, self.action_tree)

        self.decision = Decision(
                    basic_action=self.cerebellum.choose_movement(next_action, perception),
                    action=next_action)

        return self.decision


class FrontalLobe:
    """
    FrontalLobe controls decision making
    """

    def __init__(self):
        pass

    def decide_action(self, perception, memory, action_tree):
        if not action_tree:
            next_action = None
        else:
            next_action = action_tree[0] # first, MVP

        return next_action


class Cerebellum:
    """
    Cerebellum controls path planning
    """
    def __init__(self):
        pass

    def choose_movement(self, next_action, perception):
        """
        MVP movement
        :param next_action: the next required action
        :param perception: current perception
        :return: a BasicMovement
        """

        curr_pos = perception['curr_pos']
        next_movement = BasicMovement()

        if next_action and next_action.get_type() is 'MovementTo':
            desired_pos = next_action.desired_position

            if curr_pos[0] < desired_pos[0]:
                next_movement.direction = 'W'
            elif curr_pos[0] > desired_pos[0]:
                next_movement.direction = 'E'
            elif curr_pos[1] < desired_pos[1]:
                next_movement.direction = 'S'
            elif curr_pos[1] > desired_pos[1]:
                next_movement.direction = 'N'

        return next_movement
