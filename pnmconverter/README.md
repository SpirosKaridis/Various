# PPM to PGM Image Converter

## Overview

This project is a **PNM Image Converter** written in C that converts images between different formats within the Portable Anymap (PNM) file family. 
The program specifically handles transformations between **PPM (Portable Pixmap)** and **PGM (Portable Graymap)** formats in both ASCII and binary representations. 
The tool is ideal for users who need to convert colored images to grayscale or transform images into binary black-and-white formats.

### Supported Formats
- **P1 (PBM ASCII)**: Portable Bitmap (Black & White)
- **P2 (PGM ASCII)**: Portable Graymap (Grayscale)
- **P3 (PPM ASCII)**: Portable Pixmap (Color)
- **P4 (PBM Binary)**: Portable Bitmap (Binary Black & White)
- **P5 (PGM Binary)**: Portable Graymap (Binary Grayscale)
- **P6 (PPM Binary)**: Portable Pixmap (Binary Color)

## Features

- **Converts P3 to P2**: Transforms colored ASCII images (P3) to grayscale ASCII images (P2).
- **Converts P6 to P5**: Converts colored binary images (P6) to grayscale binary images (P5).
- **Converts P2 to P1**: Converts grayscale ASCII images (P2) to black-and-white ASCII images (P1).
- **Converts P5 to P4**: Converts grayscale binary images (P5) to black-and-white binary images (P4).
- Skips processing for already black-and-white formats (P1 and P4).
- Handles comment lines (starting with `#`) and various whitespace characters in the PNM files.
- Ensures integrity by verifying headers and pixel data formats.
- Supports pixel manipulation to adjust brightness levels when converting images.

## How It Works

1. **Header Verification**:
   - The program checks the PNM header (first two characters) to identify the format (P1 to P6).
   - If the format is unsupported, it terminates with an error.

2. **Image Conversion**:
   - Depending on the detected format, the program performs conversions:
     - **P3 to P2**: Converts each pixel's RGB values to grayscale using a weighted sum.
     - **P6 to P5**: Processes binary data to convert RGB to grayscale.
     - **P2 to P1** and **P5 to P4**: Converts grayscale to black-and-white based on a brightness threshold.

3. **Pixel Processing**:
   - For ASCII formats (P1, P2, P3), the program reads and converts pixel values character by character.
   - For binary formats (P4, P5, P6), it reads byte-by-byte for faster processing.

## Compilation & Usage

### Requirements
- GCC (or any C compiler)
- Standard C libraries

### Compilation
To compile the program, use the following command:
```bash
gcc -o pnm_converter converter.c
```

### Example
./pnm_converter < image.ppm > image.pgm
