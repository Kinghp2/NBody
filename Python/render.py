from vpython import *
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.animation as animation


class Renderer:

    def __init__(self, bodies, time_steps, mean_mass):
        self.bodies = bodies
        self.time_steps = time_steps
        self.rendered_elements = []
        self.mean_mass = mean_mass
        self.scene = canvas(width=1250, height=620, title='NBody')

    def render_vpython(self):
        for i in range(self.time_steps):
            for body in self.bodies:
                self.vpython_render_body(body, i)
            # sleep(1e-7)
            self.vpython_delete_objects()

    def vpython_delete_objects(self):
        for element in self.rendered_elements:
            element.visible = False
            del element

    def vpython_render_body(self, body, i):
        (x, y, z) = body.positions[i]
        (R, G, B) = body.color
        rendered_body = sphere(canvas=self.scene, pos=1e-12 * vector(z, x, y),
                               size=(body.mass*1e-13) * vector(1, 1, 1),
                               color=vector(R, G, B))
        self.rendered_elements.append(rendered_body)

    def scatter(self):
        fig = plt.figure()
        ax = fig.add_subplot(projection="3d")

        def update(t, bodies, graphs):
            ax = p3.Axes3D(fig)
            for body, graph in zip(bodies, graphs):
                (x, y, z) = body.positions[t]
                ax.scatter(x, y, z)
            return ax

        graphs = [ax.scatter([], [], []) for _ in self.bodies]
        frames = int(self.time_steps * 1e-3)
        ani = animation.FuncAnimation(
            fig, update, frames, fargs=(self.bodies, graphs), interval=20)
        ani.save('this.mp4', fps=30)
        plt.show()
