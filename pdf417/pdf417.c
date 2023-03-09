/*
 * Copyright 2003-205 by Paulo Soares.
 *
 * The contents of this file are subject to the Mozilla Public License Version 1.1
 * (the "License"); you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the License.
 *
 * The Original Code is 'pdf417lib, a library to generate the bidimensional barcode PDF417'.
 *
 * The Initial Developer of the Original Code is Paulo Soares. Portions created by
 * the Initial Developer are Copyright (C) 2003 by Paulo Soares.
 * All Rights Reserved.
 *
 * Contributor(s): all the names of the contributors are added in the source code
 * where applicable.
 *
 * Alternatively, the contents of this file may be used under the terms of the
 * LGPL license (the "GNU LIBRARY GENERAL PUBLIC LICENSE"), in which case the
 * provisions of LGPL are applicable instead of those above.  If you wish to
 * allow use of your version of this file only under the terms of the LGPL
 * License and not to allow others to use your version of this file under
 * the MPL, indicate your decision by deleting the provisions above and
 * replace them with the notice and other provisions required by the LGPL.
 * If you do not delete the provisions above, a recipient may use your version
 * of this file under either the MPL or the GNU LIBRARY GENERAL PUBLIC LICENSE.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MPL as stated above or under the terms of the GNU
 * Library General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Library general Public License for more
 * details.
 *
 * If you didn't download this code from the following link, you should check if
 * you aren't using an obsolete version:
 * http://sourceforge.net/projects/pdf417lib
 */
#include "pdf417lib.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    pdf417param p;
    FILE* f;
    pdf417init(&p);
    if (argc < 3) {
        printf("PDF417 barcode postscript generator\n"
            "Usage: pdf417 postscript_file_name barcode_text\n");
        return 0;
    }
    p.text = argv[2];
    p.options = PDF417_INVERT_BITMAP;
    paintCode(&p);
    if (p.error) {
        pdf417free(&p);
        return 0;
    }
    f = fopen(argv[1], "wb");
    if (f) {
        int cols = p.bitColumns / 8 + 1;
        int k;
        fprintf(f, "/Times findfont\n12 scalefont setfont\n100 80 moveto\n(A PDF417 example.)show\n");
        fprintf(f, "stroke\n100 100 translate\n%g %g scale\n", p.bitColumns/2.0, p.codeRows * 3/2.0);
        fprintf(f, "%d %d 1 [%d 0 0 %d 0 %d]{<", p.bitColumns, p.codeRows, p.bitColumns, -p.codeRows, p.codeRows);
        for (k = 0; k < p.lenBits; ++k) {
            if (!(k % cols))
                fprintf(f, "\n");
            fprintf(f, "%02X", (int)p.outBits[k] & 0xff);
        }
        fprintf(f, "\n>}image\nshowpage\n");
        fclose(f);
    }
    
    pdf417free(&p);
    return 0;
}
