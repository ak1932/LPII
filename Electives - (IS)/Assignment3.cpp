#include <bits/stdc++.h>
using namespace std;


int IP[] = {1, 5, 2, 0, 3, 7, 4, 6};


int IP_inv[] = {3, 0, 2, 4, 6, 1, 7, 5};


int P10[] = {2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
int P8[]  = {5, 2, 6, 3, 7, 4, 9, 8};


int EP[] = {3, 0, 1, 2, 1, 2, 3, 0};


int P4[] = {1, 3, 2, 0};


int S0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}
};
int S1[4][4] = {
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}
};


vector<int> permute(vector<int> bits, int perm[], int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = bits[perm[i]];
    return res;
}

vector<int> leftShift(vector<int> bits, int shifts) {
    vector<int> res = bits;
    rotate(res.begin(), res.begin() + shifts, res.end());
    return res;
}

vector<int> XOR(vector<int> a, vector<int> b) {
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i] = a[i] ^ b[i];
    return res;
}

vector<int> sBoxLookup(vector<int> bits, int box[4][4]) {
    int row = bits[0] * 2 + bits[3];
    int col = bits[1] * 2 + bits[2];
    int val = box[row][col];
    return { (val >> 1) & 1, val & 1 };
}


void generateKeys(vector<int> key, vector<int> &K1, vector<int> &K2) {
    vector<int> permKey = permute(key, P10, 10);
    vector<int> left(permKey.begin(), permKey.begin() + 5);
    vector<int> right(permKey.begin() + 5, permKey.end());

    left = leftShift(left, 1);
    right = leftShift(right, 1);
    vector<int> k1_input = left;
    k1_input.insert(k1_input.end(), right.begin(), right.end());
    K1 = permute(k1_input, P8, 8);

    left = leftShift(left, 2);
    right = leftShift(right, 2);
    vector<int> k2_input = left;
    k2_input.insert(k2_input.end(), right.begin(), right.end());
    K2 = permute(k2_input, P8, 8);
}


vector<int> F(vector<int> R, vector<int> K) {
    vector<int> expanded = permute(R, EP, 8);
    vector<int> xored = XOR(expanded, K);
    vector<int> left(xored.begin(), xored.begin() + 4);
    vector<int> right(xored.begin() + 4, xored.end());
    vector<int> s0out = sBoxLookup(left, S0);
    vector<int> s1out = sBoxLookup(right, S1);
    vector<int> combined = s0out;
    combined.insert(combined.end(), s1out.begin(), s1out.end());
    return permute(combined, P4, 4);
}


vector<int> encrypt(vector<int> pt, vector<int> K1, vector<int> K2) {
    vector<int> ip = permute(pt, IP, 8);
    vector<int> L(ip.begin(), ip.begin() + 4);
    vector<int> R(ip.begin() + 4, ip.end());

    vector<int> f1 = F(R, K1);
    vector<int> L1 = XOR(L, f1);
    vector<int> R1 = R;

    vector<int> f2 = F(L1, K2);
    vector<int> L2 = XOR(R1, f2);
    vector<int> R2 = L1;

    vector<int> preoutput = L2;
    preoutput.insert(preoutput.end(), R2.begin(), R2.end());

    return permute(preoutput, IP_inv, 8);
}


vector<int> decrypt(vector<int> ct, vector<int> K1, vector<int> K2) {
    vector<int> ip = permute(ct, IP, 8);
    vector<int> L(ip.begin(), ip.begin() + 4);
    vector<int> R(ip.begin() + 4, ip.end());

    vector<int> f1 = F(R, K2); 
    vector<int> L1 = XOR(L, f1);
    vector<int> R1 = R;

    vector<int> f2 = F(L1, K1); 
    vector<int> L2 = XOR(R1, f2);
    vector<int> R2 = L1;

    vector<int> preoutput = L2;
    preoutput.insert(preoutput.end(), R2.begin(), R2.end());

    return permute(preoutput, IP_inv, 8);
}


int main() {
   
    vector<int> key ;
    vector<int> plaintext;

    cout<<"Enter the 10 bit key: ";
    for(int i=0; i<10; i++){
          int k;
          cin>>k;
          key.push_back(k);
    }

    cout<<"Enter the 8 bit key: ";
    for(int i=0; i<8; i++){
          int t;
          cin>>t;
          plaintext.push_back(t);
    }

    vector<int> K1, K2;
    generateKeys(key, K1, K2);

    vector<int> ciphertext = encrypt(plaintext, K1, K2);

    cout << "Encrypted ciphertext: ";
    for (int bit : ciphertext)
        cout << bit;
    cout << endl;

    vector<int> decrypted = decrypt(ciphertext, K1, K2);

    cout << "Decrypted plaintext: ";
    for (int bit : decrypted)
        cout << bit;
    cout << endl;
    

    return 0;
}
