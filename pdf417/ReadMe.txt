A library to generate the 2D barcode PDF417

Project: http://sourceforge.net/projects/pdf417.lib
Creator: Paulo Soares (psoares@consiste.pt)
License: LGPL or MPL 1.1

This library generates a PDF417 image of the barcode in a 1x1 scale.
It requires that the displayed image be as least stretched 3 times
in the vertical direction in relation with the horizontal dimension.
See the example for this scaling adapted to the postscript output.
The example is provided for Windows and was compiled using
Visual C++ 6.0. The code can, however, be used with any ANSI C compiler.
The only assumption is that an int is at least 32 bit long.

Files needed:

pdf417lib.c - the generation code
pdf417lib.h - includes neeeded fon an application to call the library
pdf417libimp.h - includes for private use of the library

Optional file:

pdf417.c - example with postscript output


The general code usage is (pseudo-code):

#include "pdf417lib.h"

pdf417param p;
pdf417init(&p)
p.text = "Barcode text";
p.options = ....; // optional
paintCode(&p);
if (p.error) {
    // do something about the error
    pdf417free(&p);
    return;
}
// process the image here
pdf417free(&p);


Several options may be set to change the way the barcode is generated:

typedef struct _pdf417param {
    char *outBits;      // the bitmap
    int lenBits;        // the size in bytes of the bitmap
    int bitColumns;     // the number of column bits in the bitmap
    int codeRows;       // the number of code rows and bitmap lines
    int codeColumns;    // the number of code columns
    int codewords[928]; // the code words may be input. Is always output
    int lenCodewords;   // the size of the code words
    int errorLevel;     // the error level required 0-8
    char *text;         // the text
    int lenText;        // the text length or -1 for strlen on text
    int options;        // the options to generate the barcode
    float aspectRatio;  // the y/x aspect ratio
    float yHeight;      // the y/x dot ratio
    int error;          // the error returned
} pdf417param, *pPdf417param;

PDF417_USE_ASPECT_RATIO     - use aspectRatio to set the y/x dimension. Also uses yHeight
PDF417_FIXED_RECTANGLE      - make the barcode dimensions at least codeColumns by codeRows
PDF417_FIXED_COLUMNS        - make the barcode dimensions at least codeColumns
PDF417_FIXED_ROWS           - make the barcode dimensions at least codeRows
PDF417_AUTO_ERROR_LEVEL     - automatic error level depending on text size
PDF417_USE_ERROR_LEVEL      - the error level is errorLevel. The used errorLevel may be different
PDF417_USE_RAW_CODEWORDS    - use codewords instead of text
PDF417_INVERT_BITMAP        - invert the resulting bitmap

The errors returned may be:

PDF417_ERROR_SUCCESS        - no errors
PDF417_ERROR_TEXT_TOO_BIG   - the text was too big the PDF417 specifications
PDF417_ERROR_INVALID_PARAMS - invalid parameters. Only used with PDF417_USE_RAW_CODEWORDS

