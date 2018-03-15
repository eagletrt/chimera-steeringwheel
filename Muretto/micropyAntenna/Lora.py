import pyb
from pyb import UART
from pyb import ADC

data_to_send = bytearray(5)

index = 0

tim_data_enable = 0 
tim_uart_enable = 0 

def tim_data_cb(timer):
    global tim_data_enable
    tim_data_enable = 1

    #data_to_send[index] = index
    #data_to_send[index+1:index+4+1] = [1,2,3,4]

def tim_uart_cb(timer):
    global tim_uart_enable
    tim_uart_enable = 1

    #global data_to_send 
    #print(data_to_send)
    #data_to_send= bytearray(60)

class Lora(object):
    def __init__(self, delay=10):
        self.uart = UART(4, 115200)

        self.checkAntennaComunication()

        self.tim_data = pyb.Timer(4, freq=50)
        self.tim_data.callback(tim_data_cb)
        self.tim_uart = pyb.Timer(3, freq=50)
        self.tim_uart.callback(tim_uart_cb)

        self.loop()

    def loop(self):
        global tim_data_enable

        global data
        data = bytearray([0, 1, 2, 3, 4])
        global data_to_send
        global tim_uart_enable

        global index

        uart = self.uart

        while True:
            if tim_data_enable:
                tim_data_enable = 0
                #print("Creating data - Index {0}".format(index))

                # data_to_send = [APPS, BSE, Temp HV, Current HV L, Current HV R]   
                # Data Ranges 50 - 250 max 200 values
                
                #send data from 0 to 99 and repeat
                data = bytearray([ (data[0]+1)%100, (data[1]+1)%100, (data[2]+1)%100, (data[3]+1)%100, (data[4]+1)%100])                
                
                for i in range(5):
                    data_to_send[i] = data[i] + 50

            if tim_uart_enable:
                tim_uart_enable = 0
                index = 0
                t_0 = pyb.micros()

                print(data_to_send)

                uart.write(data_to_send + "\r\n")

                t_1 = pyb.micros()
                print("Tempo: {0}".format(t_1 - t_0))
                index += 1

    def speedTest(self, send_delay, send_char_length):
        uart = self.uart

        for i in range(100):
            somma_tempi = 0

            t_0 = pyb.micros()
            stringa = bytearray("{0}".format(i)+"c"*(send_char_length-1)+"\r\n")
            uart.write(stringa)
            t_1 = pyb.micros()
            pyb.delay(send_delay)
            tempo = t_1 - t_0

            print("Stringa: {2} Caratteri: {0} Tempo: {1}ns".format(i, tempo, stringa))

            """
            for j in range(10):
                t_0 = pyb.micros()
                uart.write("c"*i+"\n")
                t_1 = pyb.micros()
                somma_tempi += (t_1 - t_0) 
                media_tempi = somma_tempi / 10

            print("Numero caratteri: {0} Bitrate: {2} Tempo: {1}".format(i, media_tempi, i*8 / (media_tempi * 10e-6)))

            """
    def checkAntennaComunication(self):
        uart = self.uart

        # Check Antenna is connected and working
        uart.write("+++\r\n")

        while True:
            if uart.any():
                msg = uart.readline()[:2] 
                if (msg == b'OK'):
                    uart.write("ATCC\r\n")

                    pyb.delay(10)

                    msg = uart.readline()[:2]

                    if msg == b'OK':
                        print("Exit command mode, ready to send shit")
                        print("Antenna is connected and working")
                    else:
                        print("ERRORE!")
                        print("Antenna NOT Working")
                else:
                    print("Antenna NOT working")

                break

    def loop_old(self):
        index = 0
        uart = self.uart

        while True:
            t_0 = pyb.micros()
            uart.write("ciao Davidino::Index={0}\n".format(index))
            t_1 = pyb.micros()
            print("Tempo di invio: {0}".format(t_1 - t_0))
            index += 1

    def sendLoop(self, delay):
        print("Ready to send!")
        counter = 0
        while True:
            # Truncate the values of the ADC from 12 to 8
            #val = self.adc.read() >> 4
            #print("Sending {0}...".format(val))
            #self.uart.write("{0}\n".format(val))
            #pyb.delay(delay)

            print("Sent 64 bytes of data -- {0}".format(counter))
            self.uart.write("c"*62+"\n")

            if counter == 9:
                counter = 0

            while True:
                if self.uart.any() > 0:
                    ack = self.uart.readline()
                    break

    def recvLoop(self):
        print("Ready to receive!")
        counter = 0
        init = pyb.millis()
        while True:
            if self.uart.any():
                if counter == 9:
                    print("Received 670 bytes in {0} msec".format(pyb.millis() - init))
                    init = pyb.millis()
                    counter = 0
                val = self.uart.readline()
                #print("Received {0}".format(val))
                counter += 1
                self.uart.write("ok\n")
