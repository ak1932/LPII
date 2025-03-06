Conversation opened. 1 unread message.

Skip to content
Using Gmail with screen readers
3 of 6,502
IS (RSA) assignment
Inbox

Arinjay Patil <arinjaypatil.2004@gmail.com>
10:27 (10 hours ago)
to me

#include <bits/stdc++.h>
using namespace std;


int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    } 
    return result;
}

int modInverse(int e, int phi) {
    for(int d = 1; d<phi; d++){
         if((e*d)%phi ==  1){
            return d;
         }
    }
    return -1;
}

void pub_key(int e, int n) {
    cout << "Public Key (e, n) : (" << e << ", " << n << ")" << endl;
}


void pri_key(int d, int n) {
    cout << "Private Key (d, n) : (" << d << ", " << n << ")" << endl;
}

void encryption(int p, int q, const string &message) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    
    int e;

    for(e = 2; e<phi; e++){
        if(__gcd(e,phi) == 1){
            break;
        }
    }
   
 

    int d = modInverse(e, phi);
    pub_key(e, n);

    vector<int> encrypted;
    for (char c : message) {
        int num = c-'a' +1;
    
        encrypted.push_back(modExp(num, e, n));
    }

  
    cout << "Encrypted Message: ";
    for (int enc : encrypted) cout << enc << " ";
    cout << endl;

   pri_key(d, n);
    cout << "Decrypted Message: ";
    for (int enc : encrypted) {
        char dec = (modExp(enc, d, n) + 'a' -1);
        cout << dec;
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter the message: ";
    cin >> s;
    int p, q;
    cout << "Enter two Prime Numbers: ";
    cin >> p >> q;

    encryption(p, q, s);
    return 0;
}

