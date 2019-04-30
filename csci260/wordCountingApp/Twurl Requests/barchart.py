from matplotlib import pyplot
import numpy

#define the pie chart
labels = ['Shit', 'Fucking', 'Fuck', 'Bitches', 'Damn', 'Fucks', 'Ass', 'Shits', 'Asses']
y_pos = numpy.arange(len(labels))
sizes = [13, 9, 7, 7, 3, 2, 2, 1, 1]
    
#do the plot
pyplot.bar(y_pos, sizes, align='center', alpha=0.5)
pyplot.xticks(y_pos, labels)
pyplot.ylabel('Occurence')
pyplot.title('Profanity in Tweets')
pyplot.show()
