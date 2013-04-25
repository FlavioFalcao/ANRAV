import heatmap
import random

hm = heatmap.Heatmap()
pts = [(random.uniform(-85.529092, -85.529094), random.uniform(32.580186, 32.580190)) for x in range(100)]
hm.heatmap(pts)
hm.saveKML("ANRAV_heat1.kml")
