import socket

print("""
                Clukk
             Release V2.3
             
                URL2IP
""")
print("")
ip = " "
ip = input("Enter URL: ")
x = socket.gethostbyname(ip)
print("IP: ", x)
