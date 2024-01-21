import speech_recognition as sr
import serial

def record_volume():
    r = sr.Recognizer()
    with sr.Microphone(device_index=1) as source:
        audio = r.listen(source)
    query = r.recognize_google(audio, language='ru-RU')
    return query.lower()

def strings_replaser(replase_string):
    command = ""
    for el in replase_string:
         if el != "_":
              command = command + el
         else:
             return command
            
def strings_for_printing(original, delited):
    sort = len(delited)
    final_string = original[(int(sort)+1):]
    return final_string

def go_to_arduino(command, char):
    ser = serial.Serial("/dev/ttyAMA0", 31250)
    ser.write(bytes((command), 'utf-8'))
    ser.write(bytes(char, 'utf-8'))
    return 0

replase = record_volume().replace(" ", "_")
commands = strings_replaser(replase)
char = strings_for_printing(replase, commands)

go_to_arduino(commands, char)