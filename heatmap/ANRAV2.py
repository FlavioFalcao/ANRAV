import heatmap
import random

dotsize = 25 
hm = heatmap.Heatmap()
pts = [(random.uniform(-85.528994, -85.529448), random.uniform(32.579655, 32.580047)) for x in range(25)]
hm.heatmap(pts)
hm.saveKML("ANRAV_heat2.kml")
