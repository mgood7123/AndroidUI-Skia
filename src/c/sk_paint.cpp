/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkColorFilter.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkShader.h"

#include "include/c/sk_paint.h"

#include "src/c/sk_types_priv.h"

sk_paint_t* sk_paint_new_with_font(const sk_font_t* font) {
    return ToPaint(new SkPaint(AsFont(font)));
}

sk_font_t* sk_paint_make_font(sk_paint_t* paint) {
    return ToFont(AsPaint(paint)->makeFont());
}

sk_font_t* sk_paint_get_font(sk_paint_t* paint) {
    return ToFont(AsPaint(paint)->getFont());
}

void sk_paint_set_text_align(sk_paint_t* paint, sk_text_align_t align) {
    AsPaint(paint)->setTextAlign((SkPaint::Align)align);
}

sk_text_align_t sk_paint_get_text_align(const sk_paint_t* paint) {
    return (sk_text_align_t)AsPaint(paint)->getTextAlign();
}

void sk_paint_set_text_encoding(sk_paint_t* paint, sk_text_encoding_t encoding) {
    AsPaint(paint)->setTextEncoding((SkTextEncoding)encoding);
}

sk_text_encoding_t sk_paint_get_text_encoding(const sk_paint_t* paint) {
    return (sk_text_encoding_t)AsPaint(paint)->getTextEncoding();
}

sk_paint_t* sk_paint_new(void) {
    return ToPaint(new SkPaint());
}

sk_paint_t* sk_paint_clone(sk_paint_t* paint) {
    return ToPaint(new SkPaint(*AsPaint(paint)));
}

void sk_paint_delete(sk_paint_t* cpaint) { delete AsPaint(cpaint); }

void sk_paint_reset(sk_paint_t* cpaint) {
    AsPaint(cpaint)->reset();
}

bool sk_paint_is_antialias(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->isAntiAlias();
}

void sk_paint_set_antialias(sk_paint_t* cpaint, bool aa) {
    AsPaint(cpaint)->setAntiAlias(aa);
}

bool sk_paint_nothing_to_draw(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->nothingToDraw();
}

uint8_t sk_paint_get_alpha(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->getAlpha();
}

void sk_paint_set_alpha(sk_paint_t* cpaint, uint8_t alpha) {
    return AsPaint(cpaint)->setAlpha(alpha);
}

float sk_paint_get_alphaf(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->getAlphaf();
}

void sk_paint_set_alphaf(sk_paint_t* cpaint, float alpha) {
    return AsPaint(cpaint)->setAlphaf(alpha);
}

sk_color_t sk_paint_get_color(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->getColor();
}

void sk_paint_get_color4f(const sk_paint_t* paint, sk_color4f_t* color) {
    *color = ToColor4f(AsPaint(paint)->getColor4f());
}

void sk_paint_set_color(sk_paint_t* cpaint, sk_color_t c) {
    AsPaint(cpaint)->setColor(c);
}

void sk_paint_set_color4f(sk_paint_t* paint, sk_color4f_t* color, sk_colorspace_t* colorspace) {
    AsPaint(paint)->setColor4f(AsColor4f(*color), AsColorSpace(colorspace));
}

void sk_paint_set_shader(sk_paint_t* cpaint, sk_shader_t* cshader) {
    AsPaint(cpaint)->setShader(sk_ref_sp(AsShader(cshader)));
}

void sk_paint_set_maskfilter(sk_paint_t* cpaint, sk_maskfilter_t* cfilter) {
    AsPaint(cpaint)->setMaskFilter(sk_ref_sp(AsMaskFilter(cfilter)));
}

sk_paint_style_t sk_paint_get_style(const sk_paint_t* cpaint) {
    return (sk_paint_style_t)AsPaint(cpaint)->getStyle();
}

void sk_paint_set_style(sk_paint_t* cpaint, sk_paint_style_t style) {
    AsPaint(cpaint)->setStyle((SkPaint::Style)style);
}

float sk_paint_get_stroke_width(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->getStrokeWidth();
}

void sk_paint_set_stroke_width(sk_paint_t* cpaint, float width) {
    AsPaint(cpaint)->setStrokeWidth(width);
}

float sk_paint_get_stroke_miter(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->getStrokeMiter();
}

void sk_paint_set_stroke_miter(sk_paint_t* cpaint, float miter) {
    AsPaint(cpaint)->setStrokeMiter(miter);
}

sk_stroke_cap_t sk_paint_get_stroke_cap(const sk_paint_t* cpaint) {
    return (sk_stroke_cap_t)AsPaint(cpaint)->getStrokeCap();
}

void sk_paint_set_stroke_cap(sk_paint_t* cpaint, sk_stroke_cap_t ccap) {
    AsPaint(cpaint)->setStrokeCap((SkPaint::Cap)ccap);
}

sk_stroke_join_t sk_paint_get_stroke_join(const sk_paint_t* cpaint) {
    return (sk_stroke_join_t)AsPaint(cpaint)->getStrokeJoin();
}

void sk_paint_set_stroke_join(sk_paint_t* cpaint, sk_stroke_join_t cjoin) {
    AsPaint(cpaint)->setStrokeJoin((SkPaint::Join)cjoin);
}

void sk_paint_set_blendmode(sk_paint_t* paint, sk_blendmode_t mode) {
    AsPaint(paint)->setBlendMode((SkBlendMode)mode);
}

bool sk_paint_is_dither(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->isDither();
}

void sk_paint_set_dither(sk_paint_t* cpaint, bool isdither) {
    AsPaint(cpaint)->setDither(isdither);
}

sk_shader_t* sk_paint_get_shader(sk_paint_t* cpaint) {
    return ToShader(AsPaint(cpaint)->refShader().release());
}

sk_maskfilter_t* sk_paint_get_maskfilter(sk_paint_t* cpaint) {
    return ToMaskFilter(AsPaint(cpaint)->refMaskFilter().release());
}

void sk_paint_set_colorfilter(sk_paint_t* cpaint, sk_colorfilter_t* cfilter) {
    AsPaint(cpaint)->setColorFilter(sk_ref_sp(AsColorFilter(cfilter)));
}

sk_colorfilter_t* sk_paint_get_colorfilter(sk_paint_t* cpaint) {
    return ToColorFilter(AsPaint(cpaint)->refColorFilter().release());
}

void sk_paint_set_imagefilter(sk_paint_t* cpaint, sk_imagefilter_t* cfilter) {
    AsPaint(cpaint)->setImageFilter(sk_ref_sp(AsImageFilter(cfilter)));
}

sk_imagefilter_t* sk_paint_get_imagefilter(sk_paint_t* cpaint) {
    return ToImageFilter(AsPaint(cpaint)->refImageFilter().release());
}

sk_blendmode_t sk_paint_get_blendmode(sk_paint_t* paint) {
    return (sk_blendmode_t)AsPaint(paint)->getBlendMode();
}

void sk_paint_set_filter_quality(sk_paint_t* cpaint, sk_filter_quality_t filterQuality) {
    AsPaint(cpaint)->setFilterQuality((SkFilterQuality)filterQuality);
}

sk_filter_quality_t sk_paint_get_filter_quality(sk_paint_t* cpaint) {
    return (sk_filter_quality_t)AsPaint(cpaint)->getFilterQuality();
}

sk_path_effect_t* sk_paint_get_path_effect(sk_paint_t* cpaint) {
    return ToPathEffect(AsPaint(cpaint)->refPathEffect().release());
}

void sk_paint_set_path_effect(sk_paint_t* cpaint, sk_path_effect_t* effect) {
    AsPaint(cpaint)->setPathEffect(sk_ref_sp(AsPathEffect(effect)));
}

bool sk_paint_get_fill_path(const sk_paint_t* cpaint, const sk_path_t* src, sk_path_t* dst, const sk_rect_t* cullRect, float resScale) {
    return AsPaint(cpaint)->getFillPath(*AsPath(src), AsPath(dst), AsRect(cullRect), resScale);
}
