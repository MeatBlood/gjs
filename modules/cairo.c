/* -*- mode: C; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/* Copyright 2010 litl, LLC. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <config.h>

#include <gjs/gjs.h>

#include "cairo-private.h"

JSBool
gjs_js_define_cairo_stuff(JSContext      *context,
                          JSObject       *module_obj)
{
    jsval obj;
    JSObject *surface_proto, *pattern_proto, *gradient_proto;

    obj = gjs_cairo_context_create_proto(context, module_obj,
                                         "Context", NULL);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
    gjs_cairo_context_init(context);

    obj = gjs_cairo_surface_create_proto(context, module_obj,
                                         "Surface", NULL);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
    surface_proto = JSVAL_TO_OBJECT(obj);

#if CAIRO_HAS_IMAGE_SURFACE
    obj = gjs_cairo_image_surface_create_proto(context, module_obj,
                                               "ImageSurface", surface_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
    gjs_cairo_image_surface_init(context, JSVAL_TO_OBJECT(obj));
#endif

#if CAIRO_HAS_PS_SURFACE
    obj = gjs_cairo_ps_surface_create_proto(context, module_obj,
                                            "PSSurface", surface_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
#endif

#if CAIRO_HAS_PDF_SURFACE
    obj = gjs_cairo_pdf_surface_create_proto(context, module_obj,
                                             "PDFSurface", surface_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
#endif

#if CAIRO_HAS_SVG_SURFACE
    obj = gjs_cairo_svg_surface_create_proto(context, module_obj,
                                             "SVGSurface", surface_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
#endif

    obj = gjs_cairo_pattern_create_proto(context, module_obj,
                                         "Pattern", NULL);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
    pattern_proto = JSVAL_TO_OBJECT(obj);

    obj = gjs_cairo_gradient_create_proto(context, module_obj,
                                         "Gradient", pattern_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;
    gradient_proto = JSVAL_TO_OBJECT(obj);

    obj = gjs_cairo_linear_gradient_create_proto(context, module_obj,
                                                 "LinearGradient", gradient_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;

    obj = gjs_cairo_radial_gradient_create_proto(context, module_obj,
                                                 "RadialGradient", gradient_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;

    obj = gjs_cairo_surface_pattern_create_proto(context, module_obj,
                                                 "SurfacePattern", pattern_proto);
    if (obj == JSVAL_NULL)
        return JS_FALSE;

    return JS_TRUE;
}

GJS_REGISTER_NATIVE_MODULE("cairoNative", gjs_js_define_cairo_stuff)

