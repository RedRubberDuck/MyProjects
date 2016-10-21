import  matplotlib.pyplot
import numpy as np


def drawPoints(population):
      for j in range(len(population)):
            bac=population[j]
            matplotlib.pyplot.plot(bac[0],bac[1],'g^');

def drawLines(population,populationPrev):
    for j in range(len(population)):
        bac=population[j]
        bacPrev=populationPrev[j]
        bacX=[bac[0],bacPrev[0]]
        bacY=[bac[1],bacPrev[1]]
        matplotlib.pyplot.plot(bacX,bacY,'r--');    

            
matplotlib.pyplot.hold(True);
drawPoints(population)
if first is 1:
    drawLines(population, populationPrev)
    