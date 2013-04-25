import heatmap
import random

dotsize = 25
hm = heatmap.Heatmap()
pts = [(random.uniform(-85.528994, -85.529094), random.uniform(32.579655, 32.580188)) for x in range(25)]
hm.heatmap(pts)
hm.saveKML("ANRAV_heat3.kml") 
