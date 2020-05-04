from scripts.auxiliary import distance

EYESIGHT = 5


class Senses:

    def __init__(self):
        self.sight = Sight()
        self.perceptions = None

    def perceive(self, world, curr_pos):

        self.perceptions = {
            'curr_pos': curr_pos,
            'sight': self.sight.see(world, curr_pos)}
        return self.perceptions

    def get_status(self):
        status = '\n'
        if self.perceptions['sight']:
            for seen_pos, seen in self.perceptions['sight'].items():
                if seen['type'] is 'human':
                    description = '{seen_type} ({seen_name})'.format(
                        seen_type=seen['type'],
                        seen_name=seen['name'])
                else:
                    description = seen['type']

                status = """{status}        o {description} at {seen_pos}""".format(
                    status=status, description=description, seen_pos=seen_pos)

        return status


class Sight:

    def __init__(self):
        pass

    @staticmethod
    def see(world, curr_pos):

        seen = dict()

        for human in world.humans:
            if distance(curr_pos, human.pos) < EYESIGHT:
                seen[tuple(human.pos)] = {'type': 'human', 'name': human.name}

        for plant in world.plants:
            if distance(curr_pos, plant.pos) < EYESIGHT:
                seen[tuple(plant.pos)] = {'type': 'plant', 'name': None}

        return seen
