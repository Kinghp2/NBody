import os
import numpy as np

from Body import Body


class Loader:

    def __init__(self):
        self.dir_path = "../CPU/build/data"
        self.bodies = [Body(positions=[], id=i) for i in range(self.get_bodies_number())]
        self.time_steps = len(
            [entry for entry in os.listdir(self.dir_path) if os.path.isfile(os.path.join(self.dir_path, entry))])

    def bodies_number(self):
        with open(os.path.join(self.dir_path, "0.dat")) as f:
            rs = f.readlines()
            return len(rs)

    def load_bodies(self):
        pass

    def load_body(self, i):
        with open(os.path.join(self.dir_path, i + ".dat")) as f:
            rs = f.readlines()
            for i, r in enumerate(rs):
                x, y, z = r.split(',')
                self.bodies[i].positions.append(np.array([x, y, z]))
