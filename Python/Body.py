class Body:

    def __init__(self, positions, velocities=None, accelerations=None, id=None):
        self.positions = positions
        self.velocities = velocities
        self.accelerations = accelerations
        self.id = id

    @classmethod
    def starting_positions(cls, r_0, v_0):
        return cls(positions=[r_0], velocities=[v_0])
