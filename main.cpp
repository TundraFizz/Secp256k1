#include <secp256k1.h>
#include <iostream> // cout
#include <iomanip> // setfill, setw

static const uint8_t PRIVKEY[32] = {0xa1, 0xc0, 0x25, 0xdc, 0x31, 0x70, 0x97, 0xbe,
                                    0xa3, 0xcf, 0xbd, 0x25, 0xe1, 0xd3, 0x95, 0x21,
                                    0x60, 0x1e, 0x54, 0x99, 0x95, 0x01, 0x62, 0x70,
                                    0xa6, 0x45, 0x7a, 0x73, 0x9c, 0x1e, 0x20, 0x16};

int main() {
  secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_pubkey pubkey;

  // The public key must:
  // 1. Be uncompressed
  // 2. Be 64 bytes long OR 65 bytes long with the constant 0x04 prefix

  int i = secp256k1_ec_pubkey_create(ctx, &pubkey, PRIVKEY);

  uint8_t pubkey_serialized[65];
  size_t pubkeylen = sizeof(pubkey_serialized);

  // Create an uncompressed public key that's 64 bytes long
  secp256k1_ec_pubkey_serialize(ctx, pubkey_serialized, &pubkeylen, &pubkey, SECP256K1_EC_UNCOMPRESSED);

  // For a public key that's 65 bytes, skip the first byte because it's the constant 0x04 prefix
  for(int i = 1; i < 65; i++){
    std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)pubkey_serialized[i];
  }
  std::cout << "\n";

  secp256k1_context_destroy(ctx);
  return 0;
}
