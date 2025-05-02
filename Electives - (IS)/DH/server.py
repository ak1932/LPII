# import socket

# def power(base, exponent, mod):
#     result = 1
#     while exponent > 0:
#         if exponent % 2:
#             result = (result * base) % mod
#         base = (base * base) % mod
#         exponent //= 2
#     return result

# # Diffie-Hellman parameters
# P = int(input("Enter a prime number P: "))
# G = int(input("Enter a generator G: "))
# b = int(input("Enter Alice's private key a: "))
# B = power(G, b, P)  # Bob's public key

# server_socket = socket.socket()
# server_socket.bind(('localhost', 8080))
# server_socket.listen(1)

# print("Waiting for client...")
# conn, addr = server_socket.accept()
# print(f"Connected with {addr}")

# # Send Bob's public key
# conn.send(str(B).encode())

# # Receive Alice's public key
# A = int(conn.recv(1024).decode())

# # Compute shared secret
# shared_secret = power(A, b, P)
# print("Shared secret key (Bob):", shared_secret)

# conn.close()





import socket

def power(base , exp, mod):
    result = 1
    while(exp > 0):
        if(exp%2 == 1):
            result = (result*base)%mod
        base = (base*base)%mod
        exp //= 2
    return result




P = int(input("Enter the prime number "))
G = int(input("Enter the Generator G "))
b = int(input("Enter the bob private key "))
B = power(G, b, P)

print(f"Bob's public key {B}")

server_socket = socket.socket()
server_socket.bind(("localhost", 8080))
server_socket.listen(1)


print("Waiting for client....")
conn, addr = server_socket.accept()
print(f"Connected to {addr}")


conn.send(str(B).encode())

A = int(conn.recv(1024).decode())

print(A)
shared_key = power(A, b, P)

print(f"Shared key = {shared_key}")

conn.close()