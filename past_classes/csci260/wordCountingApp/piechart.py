from matplotlib import pyplot
import numpy

#define the pie chart
labels = ['Ass', 'Asses', 'Bitches', 'Damn', 'Fuck', 'Fucks', 'Fucking', 'Shit', 'Shits']
sizes = numpy.array([2, 1, 7, 3, 7, 2, 9, 13, 1])
colors = ['yellow', 'orange', 'aquamarine', 'purple', 'dodgerblue', 'gray', 'red', 'green', 'mediumvioletred']

#do the plot
pyplot.pie(sizes, labels=labels, colors=colors,
autopct='%1.1f%%', startangle=350)

pyplot.axis('equal')
pyplot.show()
