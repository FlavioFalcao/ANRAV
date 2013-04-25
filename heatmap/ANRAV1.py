import heatmap
import random

dotsize = 25
hm = heatmap.Heatmap()
pts = [(random.uniform(-85.529094, -85.529448), random.uniform(32.580047, 32.580188)) for x in range(25)]
hm.heatmap(pts)
hm.saveKML("ANRAV_heat1.kml")
