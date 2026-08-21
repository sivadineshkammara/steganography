# Image Steganography

> A C-based LSB image steganography system that embeds a secret file into a BMP image and retrieves it through a corresponding decode operation.

[![Language](https://img.shields.io/badge/Language-C-blue)](#)
[![Image Format](https://img.shields.io/badge/Image-BMP-lightgrey)](#)
[![Version](https://img.shields.io/badge/Version-V1-orange)](#)
[![Status](https://img.shields.io/badge/Status-In%20Development-yellow)](#)

---

## 📌 Overview

This project implements **Least Significant Bit (LSB) image steganography in C**.

The system uses a **BMP image as the carrier file** and hides a secret file inside the image by modifying the least significant bits of its image-data bytes. The changes are designed to remain visually imperceptible while allowing the embedded data to be recovered by the decoder.

The V1 implementation focuses on understanding and building the complete data path:

```text
Secret File
    │
    ▼
Encode Metadata + Secret Data
    │
    ▼
LSB Modification
    │
    ▼
BMP Carrier Image
    │
    ▼
Stego Image
    │
    ▼
LSB Extraction
    │
    ▼
Recovered Secret File
```

The project is deliberately implemented as a **low-level C file-processing application** rather than relying on image-processing libraries. This makes the project useful for studying:

- Binary file handling
- BMP image structure
- File pointers and streams
- Bitwise operations
- LSB manipulation
- Structures and enumerations
- Modular C programming
- Input validation
- Memory and buffer handling
- Encode/decode data flow

---

## 🎯 Objectives

The V1 objectives are:

- Build a working **BMP-based LSB steganography encoder**.
- Build a corresponding **decoder** capable of recovering the embedded secret.
- Understand how image bytes can be modified at the bit level without visibly changing the image.
- Calculate whether a carrier BMP has sufficient capacity for the secret payload.
- Preserve the BMP header while modifying only the required image-data bytes.
- Encode and decode the information required to reconstruct the secret file:
  - Magic string
  - Secret file extension
  - Secret file size
  - Secret file data
- Practice structured file handling using `FILE *`.
- Use C structures to maintain encoder state and file information.
- Separate encoding and decoding responsibilities into dedicated modules.
- Validate the complete workflow using `beautiful.bmp` and `secret.txt`.

---

# 🧠 How the V1 System Works

## 1. Encoding

The encoder receives:

```text
Source BMP Image
Secret File
Output Stego Image
```

Conceptually:

```text
beautiful.bmp + secret.txt
            │
            ▼
      Argument Validation
            │
            ▼
       Open Input Files
            │
            ▼
       Check BMP Capacity
            │
            ▼
      Copy BMP Header
            │
            ▼
    Encode Magic String
            │
            ▼
 Encode Secret File Extension
            │
            ▼
   Encode Secret File Size
            │
            ▼
      Encode Secret Data
            │
            ▼
 Copy Remaining Image Data
            │
            ▼
        stego.bmp
```

---

## 2. Decoding

The decoder performs the reverse operation:

```text
stego.bmp
    │
    ▼
Open Stego Image
    │
    ▼
Locate Embedded Metadata
    │
    ▼
Decode Magic String
    │
    ▼
Decode Secret File Extension
    │
    ▼
Decode Secret File Size
    │
    ▼
Decode Secret File Data
    │
    ▼
Reconstruct Secret File
    │
    ▼
Recovered secret.txt
```

The encode → decode process is therefore the primary V1 validation:

```text
beautiful.bmp
     +
secret.txt
     │
     ▼
   ENCODE
     │
     ▼
 stego.bmp
     │
     ▼
   DECODE
     │
     ▼
recovered secret.txt
```

---

# 🏗️ V1 Architecture

The architecture is based on the actual responsibilities represented by the current C skeleton rather than a generic application architecture.

```text
                         ┌─────────────────────┐
                         │       main.c        │
                         │   CLI Entry Point   │
                         └──────────┬──────────┘
                                    │
                           Operation Selection
                         (-e Encode / -d Decode)
                                    │
                    ┌───────────────┴───────────────┐
                    │                               │
                    ▼                               ▼
          ┌──────────────────┐           ┌──────────────────┐
          │    encode.c      │           │    decode.c      │
          │ Encoding Engine  │           │ Decoding Engine  │
          └────────┬─────────┘           └────────┬─────────┘
                   │                              │
                   │                              │
                   ▼                              ▼
          ┌──────────────────┐           ┌──────────────────┐
          │   EncodeInfo     │           │   DecodeInfo     │
          │ Encoder State    │           │ Decoder State    │
          └────────┬─────────┘           └────────┬─────────┘
                   │                              │
                   └──────────────┬───────────────┘
                                  │
                                  ▼
                    ┌─────────────────────────┐
                    │      BMP File Stream    │
                    │                         │
                    │ Source → Stego Image    │
                    │ Stego → Secret File     │
                    └────────────┬────────────┘
                                 │
                                 ▼
                    ┌─────────────────────────┐
                    │   LSB Bit Manipulation  │
                    │                         │
                    │ Encode byte → 8 image  │
                    │ bytes                   │
                    │                         │
                    │ Decode 8 image bytes →  │
                    │ 1 recovered byte        │
                    └─────────────────────────┘
```

### Core Module Responsibilities

| Module | Responsibility |
|---|---|
| `main.c` | Program entry point and operation selection |
| `encode.c` | Encoding workflow and embedding secret data |
| `encode.h` | `EncodeInfo` definition and encoding API |
| `decode.c` | Decoding workflow and extraction of secret data |
| `decode.h` | Decoder state and decoding API |
| `types.h` | Shared status and operation types |

The current encoder interface defines `EncodeInfo` to hold:

- Source image filename and file pointer
- Image capacity
- Bits per pixel
- Image buffer
- Secret filename and file pointer
- Secret extension
- Secret data buffer
- Secret file size
- Stego image filename and file pointer

These fields directly represent the state required by the V1 encoding pipeline.

---

# 📁 Project Structure

The V1 target structure is:

```text
Image-Steganography/
│
├── include/
│   ├── encode.h
│   ├── decode.h
│   └── types.h
│
├── src/
│   ├── main.c
│   ├── encode.c
│   └── decode.c
│
├── test/
│   ├── beautiful.bmp
│   └── secret.txt
│
├── output/
│   └── stego.bmp
│
├── README.md
└── .gitignore
```

> The exact final directory layout may change while the V1 skeleton is being reorganized. The important requirement is that encoding, decoding, shared types, test data, and program entry remain clearly separated.

---

# 🔧 Encoder Responsibilities

The encoder is divided into small operations rather than performing the entire process inside one function.

The current encoder interface defines the following responsibilities:

```text
check_operation_type()
        │
        ▼
read_and_validate_encode_args()
        │
        ▼
do_encoding()
        │
        ├── open_files()
        │
        ├── check_capacity()
        │
        ├── copy_bmp_header()
        │
        ├── encode_magic_string()
        │
        ├── encode_secret_file_extn()
        │
        ├── encode_secret_file_size()
        │
        ├── encode_secret_file_data()
        │
        └── copy_remaining_img_data()
```

The low-level embedding operation is handled by:

```text
encode_data_to_image()
        │
        ▼
encode_byte_tolsb()
```

Conceptually:

```text
Secret Byte
   10110010
       │
       ▼
Take 8 image-data bytes
       │
       ▼
Replace their LSBs
       │
       ▼
Modified image-data bytes
```

---

# 🖼️ BMP Data Handling

V1 does not attempt to decode or reconstruct the complete BMP format.

Instead, the encoder treats the BMP as a binary stream and distinguishes between:

```text
┌──────────────────────────────┐
│          BMP Header          │
├──────────────────────────────┤
│                              │
│        Image Pixel Data      │
│                              │
│  ← LSB modification occurs → │
│                              │
└──────────────────────────────┘
```

The BMP header is copied unchanged.

The image-data region provides the bytes used for LSB embedding.

The V1 encoder therefore performs:

```text
Source BMP
   │
   ├── Header ────────────────► Stego BMP
   │       unchanged
   │
   └── Image Data
           │
           ├── bytes used for hidden data
           │       ↓
           │   LSB modified
           │
           └── remaining bytes ─► copied unchanged
```

---

# 📦 Embedded Data Layout

The hidden payload is not simply the secret file contents.

V1 stores the information required to identify and reconstruct the secret file.

```text
LSB Payload
│
├── Magic String
│
├── Secret File Extension
│
├── Secret File Size
│
└── Secret File Data
```

This ordering is important because the decoder must recover the metadata before it can correctly reconstruct the secret file.

---

# 📏 Capacity Calculation

Before encoding, the carrier image must have sufficient capacity.

The basic relationship is:

```text
Available Capacity
        ≥
Required Embedded Data
```

For the V1 byte-wise LSB approach:

```text
1 secret byte
        ↓
8 image-data bytes
```

Therefore:

```text
Required Image Bytes
    =
Total Payload Bytes × 8
```

The payload includes the metadata and secret data required by the encoding format.

The encoder therefore performs a capacity check before modifying the image.

---

# 🧪 V1 Verification

The primary test case is:

```text
Carrier Image:
beautiful.bmp

Secret File:
secret.txt
```

Expected workflow:

```text
beautiful.bmp
      +
secret.txt
      │
      ▼
    Encode
      │
      ▼
  stego.bmp
      │
      ▼
    Decode
      │
      ▼
 recovered secret.txt
```

The V1 verification is successful only when the recovered secret file matches the original secret file.

---

# 🛠️ Technologies

| Technology | Purpose |
|---|---|
| C | Implementation |
| `stdio.h` / `FILE *` | Binary file handling |
| Bitwise operations | LSB manipulation |
| BMP | Carrier image format |
| GCC | Compilation |
| GDB | Debugging |
| Git | Version control |
| Linux / WSL | Development environment |

---

# 🚧 V1 Scope

## Included

- Project restructuring
- Existing skeleton integration
- Module responsibility analysis
- Argument validation
- File opening
- BMP image-size/capacity calculation
- BMP header copying
- Magic-string encoding
- Secret extension encoding
- Secret file-size encoding
- Secret-data encoding
- Remaining image-data copying
- Basic encoder
- Basic decoder
- Encode → decode verification
- V1 limitation documentation

## Intentionally Deferred

The following are **not part of V1**:

- Encryption
- Compression
- CRC32
- Sophisticated logging
- Sanitizers
- Fuzzing
- CI/CD
- Advanced error-handling frameworks
- Sophisticated build systems

The purpose of V1 is to establish a **correct and understandable steganography data path first**. Additional engineering features can be introduced only after the basic system is working reliably.

---

# 📈 V1 Development Roadmap

### Foundation

- [ ] Create project directory structure
- [ ] Create required source/header files
- [ ] Move existing skeleton into the new structure
- [ ] Understand each module
- [ ] Complete skeletal functions

### Encoding

- [ ] Validate arguments
- [ ] Open files
- [ ] Calculate BMP capacity
- [ ] Copy BMP header
- [ ] Encode magic string
- [ ] Encode secret extension
- [ ] Encode secret file size
- [ ] Encode secret data
- [ ] Copy remaining image data

### Decoding

- [ ] Implement decoder structure
- [ ] Open stego image
- [ ] Locate and decode embedded metadata
- [ ] Recover secret extension
- [ ] Recover secret file size
- [ ] Recover secret file data
- [ ] Reconstruct secret file

### Verification

- [ ] Encode `secret.txt` into `beautiful.bmp`
- [ ] Generate stego image
- [ ] Decode stego image
- [ ] Compare recovered data with original `secret.txt`
- [ ] Document V1 limitations
- [ ] Freeze V1

---

# 📌 V1 Completion Criteria

V1 is considered complete when:

```text
[✓] Project structure established
[✓] Encoder implemented
[✓] Decoder implemented
[✓] BMP header preserved
[✓] Payload metadata encoded
[✓] Secret data encoded
[✓] Stego image generated
[✓] Secret data recovered
[✓] Encode → Decode test passes
[✓] V1 limitations documented
[✓] V1 frozen
```

---

## 👤 Author

**Siva Dinesh Kammara**

M.Sc. Electromobility / Embedded Systems

GitHub: [@sivadineshkammara](https://github.com/sivadineshkammara)

---

## 📄 License

Not added yet.
