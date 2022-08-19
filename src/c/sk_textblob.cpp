/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkSerialProcs.h"
#include "include/core/SkTextBlob.h"

#include "include/c/sk_textblob.h"

#include "src/c/sk_types_priv.h"


void sk_textblob_ref(const sk_textblob_t* blob) {
    SkSafeRef(AsTextBlob(blob));
}

void sk_textblob_unref(const sk_textblob_t* blob) {
    SkSafeUnref(AsTextBlob(blob));
}

uint32_t sk_textblob_get_unique_id(const sk_textblob_t* blob) {
    return AsTextBlob(blob)->uniqueID();
}

void sk_textblob_get_bounds(const sk_textblob_t* blob, sk_rect_t* bounds) {
    *bounds = ToRect(AsTextBlob(blob)->bounds());
}

int sk_textblob_get_intercepts(const sk_textblob_t* blob, const float bounds[2], float intervals[], const sk_paint_t* paint) {
    return AsTextBlob(blob)->getIntercepts(bounds, intervals, AsPaint(paint));
}

// serialization and deserialization requires SkSerialProcs
// use empty for now

sk_data_t* sk_textblob_serialize(const sk_textblob_t* blob) {
    SkSerialProcs procs;
    return ToData(AsTextBlob(blob)->serialize(procs).release());
}

sk_textblob_t* sk_textblob_deserialize(const sk_data_t* data) {
    SkDeserialProcs procs;
    const SkData* skdata = AsData(data);
    return ToTextBlob(SkTextBlob::Deserialize(skdata->data(), skdata->size(), procs).release());
}


sk_textblob_builder_t* sk_textblob_builder_new(void) {
    return ToTextBlobBuilder(new SkTextBlobBuilder());
}

void sk_textblob_builder_delete(sk_textblob_builder_t* builder) {
    delete AsTextBlobBuilder(builder);
}

sk_textblob_t* sk_textblob_builder_make(sk_textblob_builder_t* builder) {
    return ToTextBlob(AsTextBlobBuilder(builder)->make().release());
}

void sk_textblob_builder_alloc_run(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float x, float y, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(AsTextBlobBuilder(builder)->allocRun(AsFont(*font), count, x, y, AsRect(bounds)));
}

void sk_textblob_builder_alloc_run_pos_h(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float y, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(AsTextBlobBuilder(builder)->allocRunPosH(AsFont(*font), count, y, AsRect(bounds)));
}

void sk_textblob_builder_alloc_run_pos(sk_textblob_builder_t* builder, const sk_font_t* font, int count, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(AsTextBlobBuilder(builder)->allocRunPos(AsFont(*font), count, AsRect(bounds)));
}

void sk_textblob_builder_alloc_run_rsxform(sk_textblob_builder_t* builder, const sk_font_t* font, int count, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(AsTextBlobBuilder(builder)->allocRunRSXform(AsFont(*font), count));
}

// (obsolete)

#include "src/core/SkTextBlobPriv.h"

void sk_textblob_builder_alloc_run_text(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float x, float y, int textByteCount, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(SkTextBlobBuilderPriv::AllocRunText(AsTextBlobBuilder(builder), AsFont(*font), count, x, y, textByteCount, SkString(), AsRect(bounds)));
}

void sk_textblob_builder_alloc_run_text_pos_h(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float y, int textByteCount, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(SkTextBlobBuilderPriv::AllocRunTextPosH(AsTextBlobBuilder(builder), AsFont(*font), count, y, textByteCount, SkString(), AsRect(bounds)));
}

void sk_textblob_builder_alloc_run_text_pos(sk_textblob_builder_t* builder, const sk_font_t* font, int count, int textByteCount, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
    *runbuffer = ToTextBlobBuilderRunBuffer(SkTextBlobBuilderPriv::AllocRunTextPos(AsTextBlobBuilder(builder), AsFont(*font), count, textByteCount, SkString(), AsRect(bounds)));
}
