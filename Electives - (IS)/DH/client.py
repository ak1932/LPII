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
# a = int(input("Enter Alice's private key a: "))
# A = power(G, a, P)



# client_socket = socket.socket()
# client_socket.connect(('localhost', 8080))

# # Receive Bob's public key
# B = int(client_socket.recv(1024).decode())

# # Send Alice's public key
# client_socket.send(str(A).encode())

# # Compute shared secret
# shared_secret = power(B, a, P)
# print("Shared secret key (Alice):", shared_secret)

# client_socket.close()







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
a = int(input("Enter the alice private key "))
A = power(G, a, P)

print(f"Alice's public key {A}")

client_socket = socket.socket()
client_socket.connect(("localhost", 8080))

B = int(client_socket.recv(1024).decode())

client_socket.send(str(A).encode())
 
print(B)

shared_key = power(B, a, P)

print(f"Shared key = {shared_key}")

client_socket.close()