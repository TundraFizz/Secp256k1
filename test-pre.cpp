#include "precompiled/secp256k1.h"

int main() {
  const uint8_t privateKey[32] = {0xab, 0xcd, 0xef, 0x12, 0x03, 0x40, 0x56, 0x00,
                                  0x78, 0x90, 0x01, 0x11, 0x22, 0x33, 0xaa, 0xbb,
                                  0xcc, 0x24, 0x68, 0x0a, 0xbc, 0xde, 0xf0, 0x00,
                                  0x01, 0x23, 0x45, 0x67, 0x89, 0x0a, 0xbc, 0xde};
  char* test = Wrapper(privateKey);
  std::cout << "# " << test << "\n";
  delete[] test;
  return 0;
}

/* Private Key
 * abcdef1203405600789001112233aabbcc24680abcdef00001234567890abcde
 *
 * Public Key
 * 64c9992d70d56cf60383b86dcba395ee0ccdb780b13d1b52803b010ae62574b68ebc46f0b25acf3721da182a180b985500669ec8541244752ec1331ea61aacee
 *
 * Keccak256 Hash
 * ?
 *
 * Address
 * 0xe7B8a14E8338963E64fB146cd22746B543D339e8
 */
