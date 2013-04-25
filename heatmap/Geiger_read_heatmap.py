import heatmap
import csv      #this will help read the csv values

hm = heatmap.Heatmap()
f = open('Geiger.csv','r')  #may need to change the filename

pts = []        #number of points will be added as they come in

for line in filename.readlines():       #read in each lat/long and radiation
    row = line.split(',')

    latitude = row[2]/10000000
    longitude = row[3]/10000000
    counts = row[1]

    opacity = counts            #strength of radiation
    pts.append = (latitude, longitude) #location of radiation


hm.heatmap(pts)
hm.saveKML("ANRAV_heatmap.kml")
f.close()
