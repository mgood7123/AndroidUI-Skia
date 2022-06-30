/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_managed_id_change_listener_DEFINED
#define sk_managed_id_change_listener_DEFINED

#include "sk_xamarin.h"

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

typedef void (*sk_id_change_listener_changed_proc)(sk_id_change_listener_t* d, void* context);
typedef void (*sk_id_change_listener_destroy_proc)(sk_id_change_listener_t* d, void* context);

typedef struct {
    sk_id_change_listener_changed_proc fChanged;
    sk_id_change_listener_destroy_proc fDestroy;
} sk_id_change_listener_procs_t;

SK_X_API sk_id_change_listener_t* sk_managed_id_change_listener_new(void* context);
SK_X_API void sk_managed_id_change_listener_delete(sk_id_change_listener_t*);
SK_X_API void sk_managed_id_change_listener_mark_should_deregister(sk_id_change_listener_t*);
SK_X_API bool sk_managed_id_change_listener_should_deregister(sk_id_change_listener_t*);
SK_X_API void sk_managed_id_change_listener_set_procs(sk_id_change_listener_procs_t procs);

SK_C_PLUS_PLUS_END_GUARD

#endif
