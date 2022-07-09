import os
import numpy as np

from Body import Body
import pandas as pd


class Loader:

    def __init__(self):
        self.dir_path = "../CPU/build/data"
        self.bodies = []
        self.N = len(
            [entry for entry in os.listdir(self.dir_path) if os.path.isfile(os.path.join(self.dir_path, entry))])

    def get_time_steps(self):
        with open(os.path.join(self.dir_path, "0.dat")) as f:
            rs = f.readlines()
            return len(rs)

    def load_bodies(self):
        masses = 0
        for i in range(self.N):
            self.load_body(i)
            masses += self.bodies[i].mass
        return self.bodies, masses/len(self.bodies)

    def load_body(self, i):
        df = pd.read_csv(os.path.join(self.dir_path, str(i)+".csv"))
        print(df.head())
