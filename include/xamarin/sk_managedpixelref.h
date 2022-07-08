/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_managedpixelref_DEFINED
#define sk_managedpixelref_DEFINED

#include "sk_xamarin.h"

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

typedef void (*sk_pixel_ref_destroy_proc)(sk_pixel_ref_t* d, void* context);

typedef struct {
    sk_pixel_ref_destroy_proc fDestroy;
} sk_pixel_ref_procs_t;

SK_X_API sk_pixel_ref_t* sk_managedpixelref_new_from_existing(void* context, void* pixelRef);
SK_X_API sk_pixel_ref_t* sk_managedpixelref_new(void* context, int32_t, int32_t, void*, size_t);
SK_X_API void sk_managedpixelref_delete(sk_pixel_ref_t*);
SK_X_API sk_isize_t sk_managedpixelref_dimensions(sk_pixel_ref_t*);
SK_X_API int32_t sk_managedpixelref_width(sk_pixel_ref_t*);
SK_X_API int32_t sk_managedpixelref_height(sk_pixel_ref_t*);
SK_X_API size_t sk_managedpixelref_rowBytes(sk_pixel_ref_t*);
SK_X_API void* sk_managedpixelref_pixels(sk_pixel_ref_t*);
SK_X_API void* sk_managedpixelref_pixel_ref(sk_pixel_ref_t* d);
SK_X_API uint32_t sk_managedpixelref_generation_id(sk_pixel_ref_t*);
SK_X_API void sk_managedpixelref_notify_pixels_changed(sk_pixel_ref_t*);
SK_X_API bool sk_managedpixelref_is_immutable(sk_pixel_ref_t*);
SK_X_API void sk_managedpixelref_set_immutable(sk_pixel_ref_t*);
SK_X_API void sk_managedpixelref_add_generation_id_listener(sk_pixel_ref_t*, sk_idchangelistener_t*);
SK_X_API void sk_managedpixelref_notify_added_to_cache(sk_pixel_ref_t*);
SK_X_API void sk_managedpixelref_set_procs(sk_pixel_ref_procs_t procs);

SK_C_PLUS_PLUS_END_GUARD

#endif
