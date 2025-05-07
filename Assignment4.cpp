#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

// class SAES {
// private:
//     string key;
//     vector<string> key_list;
//     vector<vector<char>> s_box = {
//         {'9', '4', 'A', 'B'},
//         {'D', '1', '8', '5'},
//         {'6', '2', '0', '3'},
//         {'C', 'E', 'F', '7'}
//     };
//     vector<vector<char>> inv_s_box = {
//         {'A', '5', '9', 'B'},
//         {'1', '7', '8', '5'},
//         {'6', '0', '2', '3'},
//         {'C', '4', 'D', 'E'}
//     };
//     vector<string> rcon = {"00000000", "10000000", "00110000"};

//     string xor_bin(string a, string b) {
//         string result;
//         for (int i = 0; i < a.length(); i++)
//             result += (a[i] == b[i]) ? '0' : '1';
//         return result;
//     }

//     string rot_word(string word) {
//         return word.substr(4) + word.substr(0, 4);
//     }

//     string sub_word(string word, vector<vector<char>> sbox) {
//         return nibble_substitution(word, sbox, 8);
//     }

//     vector<string> generate_keys(string key_bin) {
//         vector<string> w = {key_bin.substr(0, 8), key_bin.substr(8)};
//         for (int i = 2; i < 6; ++i) {
//             string wi;
//             if (i % 2 == 0) {
//                 string temp = sub_word(rot_word(w[i - 1]), s_box);
//                 string t = xor_bin(temp, rcon[i / 2]);
//                 wi = xor_bin(t, w[i - 2]);
//             } else {
//                 wi = xor_bin(w[i - 1], w[i - 2]);
//             }
//             w.push_back(wi);
//         }
//         return {w[0] + w[1], w[2] + w[3], w[4] + w[5]};
//     }

//     string nibble_substitution(string state, vector<vector<char>> sbox, int
//     len = 16) {
//         string result;
//         for (int i = 0; i < len; i += 4) {
//             string nibble = state.substr(i, 4);
//             int row = stoi(nibble.substr(0, 2), nullptr, 2);
//             int col = stoi(nibble.substr(2, 2), nullptr, 2);
//             int val = stoi(string(1, sbox[row][col]), nullptr, 16);
//             result += bitset<4>(val).to_string();
//         }
//         return result;
//     }

//     string shift_rows(string state) {
//         return state.substr(0, 4) + state.substr(12, 4) + state.substr(8, 4)
//         + state.substr(4, 4);
//     }

//     string inv_shift_rows(string state) {
//         return state.substr(0, 4) + state.substr(12, 4) + state.substr(8, 4)
//         + state.substr(4, 4);
//     }

//     int gf_mult(int a, int b) {
//         int product = 0;
//         a &= 0xF;
//         b &= 0xF;

//         while (a && b) {
//             if (b & 1) product ^= a;
//             a <<= 1;
//             if (a & 0x10)
//                 a ^= 0b10011;
//             b >>= 1;
//         }
//         return product;
//     }

//     string mix_columns(string state) {
//         vector<int> n;
//         for (int i = 0; i < 16; i += 4)
//             n.push_back(stoi(state.substr(i, 4), nullptr, 2));
//         swap(n[1], n[2]);
//         vector<int> result = {
//             n[0] ^ gf_mult(4, n[2]),
//             n[2] ^ gf_mult(4, n[0]),
//             n[1] ^ gf_mult(4, n[3]),
//             n[3] ^ gf_mult(4, n[1]),
//         };
//         string res;
//         for (int val : result)
//             res += bitset<4>(val).to_string();
//         return res;
//     }

//     string inv_mix_columns(string state) {
//         vector<int> n;
//         for (int i = 0; i < 16; i += 4)
//             n.push_back(stoi(state.substr(i, 4), nullptr, 2));
//         swap(n[1], n[2]);
//         vector<int> result = {
//             gf_mult(9, n[0]) ^ gf_mult(2, n[2]),
//             gf_mult(9, n[2]) ^ gf_mult(2, n[0]),
//             gf_mult(9, n[1]) ^ gf_mult(2, n[3]),
//             gf_mult(9, n[3]) ^ gf_mult(2, n[1]),
//         };
//         string res;
//         for (int val : result)
//             res += bitset<4>(val).to_string();
//         return res;
//     }

//     string add_round_key(string state, string key) {
//         return xor_bin(state, key);
//     }

// public:
//     SAES(string k) {
//         key = k;
//         key_list = generate_keys(key);
//     }

//     string encrypt(string plaintext) {
//         string state = add_round_key(plaintext, key_list[0]);
//         state = nibble_substitution(state, s_box);
//         state = shift_rows(state);
//         state = mix_columns(state);
//         state = add_round_key(state, key_list[1]);
//         state = nibble_substitution(state, s_box);
//         state = shift_rows(state);
//         return add_round_key(state, key_list[2]);
//     }

//     string decrypt(string ciphertext) {
//         string state = add_round_key(ciphertext, key_list[2]);
//         state = inv_shift_rows(state);
//         state = nibble_substitution(state, inv_s_box);
//         state = add_round_key(state, key_list[1]);
//         state = inv_mix_columns(state);
//         state = inv_shift_rows(state);
//         state = nibble_substitution(state, inv_s_box);
//         return add_round_key(state, key_list[0]);
//     }
// };

// // Example usage
// int main() {
//     string key = "0100101011110101";
//     string plaintext = "1101011100101000";

//     SAES saes(key);
//     string cipher = saes.encrypt(plaintext);
//     string decrypted = saes.decrypt(cipher);

//     cout << "Plaintext:  " << plaintext << endl;
//     cout << "Encrypted:  " << cipher << endl;
//     cout << "Decrypted:  " << decrypted << endl;

//     return 0;
// }

class SAES {
 private:
  string key;
  vector<string> key_list;
  vector<vector<char>> s_box = {{'9', '4', 'A', 'B'},
                                {'D', '1', '8', '5'},
                                {'6', '2', '0', '3'},
                                {'C', 'E', 'F', '7'}};
  vector<vector<char>> inv_s_box = {{'A', '5', '9', 'B'},
                                    {'1', '7', '8', '5'},
                                    {'6', '0', '2', '3'},
                                    {'C', '4', 'D', 'E'}};

  vector<string> rcon = {"00000000", "10000000", "00110000"};

  string XOR(string a, string b) {
    string res;
    for (int i = 0; i < a.size(); i++) {
      res += (a[i] == b[i]) ? '0' : '1';
    }

    return res;
  }

  string rot_word(string word) { return word.substr(4) + word.substr(0, 4); }

  string nibble_subs(string word, vector<vector<char>> s_box, int len = 16) {
    string result;
    for (int i = 0; i < len; i += 4) {
      string nible = word.substr(i, 4);
      int row = stoi(nible.substr(0, 2), nullptr, 2);
      int col = stoi(nible.substr(2, 2), nullptr, 2);
      int val = stoi(string(1, s_box[row][col]), nullptr, 16);

      result += bitset<4>(val).to_string();
    }

    return result;
  }

  string subs_word(string word, vector<vector<char>> s_box) {
    return nibble_subs(word, s_box, 8);
  }

  vector<string> generate_key(string key) {
    vector<string> w = {key.substr(0, 8), key.substr(8)};
    for (int i = 2; i < 6; ++i) {
      string wi;
      if (i % 2 == 0) {
        string temp = subs_word(rot_word(w[i - 1]), s_box);
        string t = XOR(temp, rcon[i / 2]);
        wi = XOR(t, w[i - 2]);
      } else {
        wi = XOR(w[i - 1], w[i - 2]);
      }
      w.push_back(wi);
    }
    return {w[0] + w[1], w[2] + w[3], w[4] + w[5]};
  }

  string shift_row(string word) {
    return word.substr(0, 4) + word.substr(12, 4) + word.substr(8, 4) +
           word.substr(4, 4);
  }

  string inv_shift_row(string word) {
    return word.substr(0, 4) + word.substr(12, 4) + word.substr(8, 4) +
           word.substr(4, 4);
  }

  int gf_mul(int a, int b) {
    int product = 0;
    a &= 0xF;
    b &= 0xF;

    while (a && b) {
      if (b & 1) {
        product ^= a;
      }
      a <<= 1;

      if (a & 0x10) {
        a ^= 0b10011;
      }

      b >>= 1;
    }

    return product;
  }

  string mix_col(string word) {
    vector<int> n;
    for (int i = 0; i < 16; i += 4) {
      n.push_back(stoi(word.substr(i, 4), nullptr, 2));
    }
    swap(n[1], n[2]);
    vector<int> result{n[0] ^ gf_mul(4, n[2]), n[2] ^ gf_mul(4, n[0]),
                       n[1] ^ gf_mul(4, n[3]), n[3] ^ gf_mul(4, n[1])};

    string res;
    for (auto it : result) {
      res += bitset<4>(it).to_string();
    }

    return res;
  }

  string inv_mix_col(string word) {
    vector<int> n;
    for (int i = 0; i < 16; i += 4) {
      n.push_back(stoi(word.substr(i, 4), nullptr, 2));
    }
    swap(n[1], n[2]);
    vector<int> result{
        gf_mul(9, n[0]) ^ gf_mul(2, n[2]), gf_mul(9, n[2]) ^ gf_mul(2, n[0]),
        gf_mul(9, n[1]) ^ gf_mul(2, n[3]), gf_mul(9, n[3]) ^ gf_mul(2, n[1])};

    string res;
    for (auto it : result) {
      res += bitset<4>(it).to_string();
    }

    return res;
  }

  string addRoundKey(string word, string key) { return XOR(word, key); }

 public:
  SAES(string k) {
    key = k;
    key_list = generate_key(k);
  }

  string encryption(string pt) {
    string state = addRoundKey(pt, key_list[0]);
    state = nibble_subs(state, s_box);
    state = shift_row(state);
    state = mix_col(state);
    state = addRoundKey(state, key_list[1]);
    state = nibble_subs(state, s_box);
    state = shift_row(state);
    return addRoundKey(state, key_list[2]);
  }

  string decryption(string pt) {
    string state = addRoundKey(pt, key_list[2]);
    state = inv_shift_row(state);
    state = nibble_subs(state, inv_s_box);
    state = addRoundKey(state, key_list[1]);
    state = inv_mix_col(state);
    state = inv_shift_row(state);
    state = nibble_subs(state, inv_s_box);
    return addRoundKey(state, key_list[0]);
  }
};

int main() {
  string key = "0100101011110101";
  string plaintext = "1101011100101000";

  SAES saes(key);
  string cipher = saes.encryption(plaintext);
  string decrypted = saes.decryption(cipher);

  cout << "Plaintext:  " << plaintext << endl;
  cout << "Encrypted:  " << cipher << endl;
  cout << "Decrypted:  " << decrypted << endl;

  return 0;
}
