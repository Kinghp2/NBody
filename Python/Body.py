class Body:

    def __init__(self, mass, positions, velocities=None, accelerations=None, id=None, color=(255, 255, 255)):
        self.mass = mass
        self.positions = positions
        self.velocities = velocities
        self.accelerations = accelerations
        self.id = id
        self.color = color

    @classmethod
    def starting_positions(cls, r_0, v_0):
        return cls(positions=[r_0], velocities=[v_0])
