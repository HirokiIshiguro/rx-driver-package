from cryptography.hazmat.primitives.keywrap import aes_key_wrap, aes_key_unwrap
from cryptography.hazmat.primitives.ciphers.aead import AESCCM
import os
import sys

def wrap_enckey(kek, enckey):
    wrapped_data = None
    wrapped_data =  aes_key_wrap(kek, enckey)
    return wrapped_data

