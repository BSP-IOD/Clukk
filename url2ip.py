import socket

print("\n" * 100)
print("""
   ______   __            __      __
  / ____/  / /  __  __   / /__   / /__
 / /      / /  / / / /  / //_/  / //_/
/ /___   / /  / /_/ /  /  <    /  <
\____/  /_/   \____/  /_/|_|  /_/|_|

             Release V2.1
             
                URL2IP
""")

ip = " "

ip = input("Enter URL: ")

x = socket.gethostbyname(ip)
print("IP: ", x)
