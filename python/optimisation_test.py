import numpy as np
from vispy.plot import Fig
from vispy import app
from scipy.optimize import rosen, rosen_der


fig = Fig()

s = 0.05  # Try s=1, 0.25, 0.1, or 0.05
X = np.linspace(-1, 1)  # Could use linspace instead if dividing
Y = np.linspace(-1, 1)  # evenly instead of stepping...

# Create the mesh grid(s) for all X/Y combos.
X, Y = np.meshgrid(X, Y)
Z = rosen([X,Y])
X = np.arange(0,Z.shape[1])
Y = np.arange(0,Z.shape[0])

#surf = ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm,
#                       linewidth=0, antialiased=False)  # Try coolwarm vs jet

ax = fig[0,0]
ax.surface(x=X, y=Y, zdata=np.array(Z))
fig.show(run=True)