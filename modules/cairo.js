// Copyright 2010 litl, LLC. All Rights Reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

const Lang = imports.lang;

const Antialias = {
    DEFAULT: 0,
    NONE: 1,
    GRAY: 2,
    SUBPIXEL: 3
};

const Extend = {
    NONE : 0,
    REPEAT : 1,
    REFLECT : 2,
    PAD : 3
};

const FillRule = {
    WINDING: 0,
    EVEN_ODD: 1
};

const Filter = {
    FAST : 0,
    GOOD : 1,
    BEST : 2,
    NEAREST : 3,
    BILINEAR : 4,
    GAUSSIAN : 5
};

const FontSlant = {
    NORMAL: 0,
    ITALIC: 1,
    OBLIQUE: 2
};

const FontWeight = {
    NORMAL : 0,
    BOLD : 1
};

const Format = {
    ARGB32 : 0,
    RGB24 : 1,
    A8 : 2,
    A1 : 3,
    // The value of 4 is reserved by a deprecated enum value
    RGB16_565: 5
};

const LineCap = {
    BUTT: 0,
    ROUND: 1,
    SQUASH: 2
};

const LineJoin = {
    MITER: 0,
    BOUND: 1,
    BEVEL: 2
};

const Operator = {
    CLEAR: 0,
    SOURCE: 1,
    OVER: 2,
    IN : 3,
    OUT : 4,
    ATOP : 5,
    DEST : 6,
    DEST_OVER : 7,
    DEST_IN : 8,
    DEST_OUT : 9,
    DEST_ATOP : 10,
    XOR : 11,
    ADD : 12,
    SATURATE : 13
};

// Merge stuff defined in native code
Lang.copyProperties(imports.cairoNative, this);

