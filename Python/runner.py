import render
from load import Loader
from render import Renderer


class Runner:

    def __init__(self):
        self.loader = Loader()

    def run(self):
        data, mean_mass = self.loader.load_bodies()
        print('Finish retrieving data')
        time_step = self.loader.get_time_steps()
        renderer = Renderer(data, time_step, mean_mass)
        renderer.render_vpython()