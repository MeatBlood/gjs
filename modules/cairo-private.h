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

#ifndef __CAIRO_PRIVATE_H__
#define __CAIRO_PRIVATE_H__

#include <cairo.h>

typedef struct {
    void *dummy;
    JSContext  *context;
    JSObject   *object;
    cairo_surface_t *surface;
} GjsCairoSurface;

JSBool gjs_js_define_cairo_stuff(JSContext *context,
                                 JSObject  *module_obj);

jsval gjs_cairo_context_create_proto(JSContext *context, JSObject *module,
                                     const char *proto_name, JSObject *parent);
cairo_t *gjs_cairo_context_get_cr(JSContext *context,
                                  JSObject *object);
JSObject * gjs_cairo_context_from_cr(JSContext *context,
                                     cairo_t *cr);
void gjs_cairo_context_init(JSContext *context);

/* surface */
jsval gjs_cairo_surface_create_proto(JSContext *context, JSObject *module,
                                     const char *proto_name, JSObject *parent);
void gjs_cairo_surface_construct(JSContext *context, JSObject *obj, cairo_surface_t *surface);
void gjs_cairo_surface_finalize_surface(JSContext *context, JSObject  *obj);
cairo_surface_t * gjs_cairo_surface_get_surface(JSContext *context,
                                                JSObject *object);

/* image surface */
#ifdef CAIRO_HAS_IMAGE_SURFACE
jsval gjs_cairo_image_surface_create_proto(JSContext *context, JSObject *module,
                                           const char *proto_name, JSObject *parent);
void gjs_cairo_image_surface_init(JSContext *context, JSObject *obj);
#endif

/* postscript surface */
#ifdef CAIRO_HAS_PS_SURFACE
jsval gjs_cairo_ps_surface_create_proto(JSContext *context, JSObject *module,
                                        const char *proto_name, JSObject *parent);
#endif

/* pdf surface */
#ifdef CAIRO_HAS_PDF_SURFACE
jsval gjs_cairo_pdf_surface_create_proto(JSContext *context, JSObject *module,
                                         const char *proto_name, JSObject *parent);
#endif

/* svg surface */
#ifdef CAIRO_HAS_SVG_SURFACE
jsval gjs_cairo_svg_surface_create_proto(JSContext *context, JSObject *module,
                                         const char *proto_name, JSObject *parent);
#endif

/* pattern */
typedef struct {
    void *dummy;
    JSContext  *context;
    JSObject   *object;
    cairo_pattern_t *pattern;
} GjsCairoPattern;

jsval gjs_cairo_pattern_create_proto(JSContext *context, JSObject *module,
                                     const char *proto_name, JSObject *parent);
void gjs_cairo_pattern_construct(JSContext *context, JSObject *obj, cairo_pattern_t *pattern);
void gjs_cairo_pattern_finalize_pattern(JSContext *context, JSObject *obj);
cairo_pattern_t * gjs_cairo_pattern_get_pattern(JSContext *context, JSObject *object);

/* gradient */
jsval gjs_cairo_gradient_create_proto(JSContext *context, JSObject *module,
                                     const char *proto_name, JSObject *parent);

#endif /* __CAIRO_PRIVATE_H__ */

