class Decision:
    def __init__(self, basic_action=None, action=None):
        self.basic_action = basic_action
        self.action = action


class Action:
    def __init__(self, action_type='Generic', goal=None, sub_actions=[]):
        self.type = action_type
        self.goal = goal
        self.sub_actions = sub_actions

    def get_type(self):
        return self.type

    def get_goal(self):
        return self.goal

    def set_subactions(self, sub_actions):
        self.sub_actions = sub_actions


class BasicMovement(Action):
    def __init__(self, direction=None):
        Action.__init__(self, 'Movement', None, [])
        self.direction = direction


class BasicDrink(Action):
    def __init__(self, drinkable=None):
        Action.__init__(self, 'Drink', None, [])
        self.drinkable = drinkable


class BasicEat(Action):
    def __init__(self, edible=None):
        Action.__init__(self, 'Drink', None, [])
        self.edible = edible


class BasicTake(Action):
    def __init__(self, takeable=None):
        Action.__init__(self, 'Take', None, [])
        self.takeable = takeable






