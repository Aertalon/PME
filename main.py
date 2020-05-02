import scripts.environment as e
from scripts.plant import Plant
import scripts.human as human
import scripts.auxiliary as aux

w = e.World()

magellano = human.Human('Magellano')

for idx in range(10):
    p = Plant(pos=aux.random_position(w))
    w.add_plant(p)

w.add_human(magellano)


for time in range(100):
    w.update()



# run tests: python -m unittest discover