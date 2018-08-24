import serial
from matplotlib import pyplot as plt
from matplotlib import animation
import tkinter as tk

BAUD_RATE = 9600
DELAY_TIME_MS = 10

REF_VOLTAGE = 5
ADC_FACTOR = 1.0 / 1024
SERIAL_PATH = "dev/ttyUSB0"

def initFrame():
    frame = tk.Tk()

def initPlot():
    fig = plt.figure()
    axis = fig.add_subplot(1, 1, 1)
    
def initSerial():
    serialPort = serial.Serial(SERIAL_PATH, BAUD_RATE)
    serialPort.flush()
    return serialPort

# convert char reading into int and then return actual voltage
def takeReading(serialPort):
    return ord(serialPort.read()) * ADC_FACTOR * REF_VOLTAGE

if __name__ == "__main__":
    # main
    pass