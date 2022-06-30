/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_managed_id_change_listener_list_DEFINED
#define sk_managed_id_change_listener_list_DEFINED

#include "sk_xamarin.h"

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

typedef void (*sk_id_change_listener_list_destroy_proc)(sk_id_change_listener_list_t* d, void* context);

typedef struct {
    sk_id_change_listener_list_destroy_proc fDestroy;
} sk_id_change_listener_list_procs_t;

SK_X_API sk_id_change_listener_list_t* sk_managed_id_change_listener_list_new(void* context);
SK_X_API void sk_managed_id_change_listener_list_delete(sk_id_change_listener_list_t*);
SK_X_API void sk_managed_id_change_listener_list_add(sk_id_change_listener_list_t*, sk_id_change_listener_t*, bool single_threaded);
SK_X_API int32_t sk_managed_id_change_listener_list_count(sk_id_change_listener_list_t*);
SK_X_API void sk_managed_id_change_listener_list_changed(sk_id_change_listener_list_t*, bool single_threaded);
SK_X_API void sk_managed_id_change_listener_list_reset(sk_id_change_listener_list_t*, bool single_threaded);
SK_X_API void sk_managed_id_change_listener_list_set_procs(sk_id_change_listener_list_procs_t procs);

SK_C_PLUS_PLUS_END_GUARD

#endif
