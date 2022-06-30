/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_id_change_listener_DEFINED
#define sk_id_change_listener_DEFINED

#include "include/c/sk_id_change_listener.h"
#include "src/c/sk_types_priv.h"

static inline SkIDChangeListener* AsSkIDChangeListener(sk_id_change_listener_t* d) {
    return reinterpret_cast<SkIDChangeListener*>(d);
}

static sk_id_change_listener_procs_t gProcs;

void changed(SkIDChangeListener* d, void* context) {
    if (gProcs.fChanged) {
        gProcs.fChanged(ToSkIDChangeListener(d), context);
    }
}

sk_id_change_listener_t* sk_id_change_listener_new(void* context) {
    return ToSKIDChangeListener(new SkIDChangeListener(context));
}

void sk_id_change_listener_delete(sk_id_change_listener_t* d) { delete AsManagedAllocator(d); }

void sk_id_change_listener_set_procs(sk_id_change_listener_procs_t procs) {
    gProcs = procs;

    SkManagedAllocator::Procs p;
    p.fAllocPixelRef = allocPixelRef;

    SkManagedAllocator::setProcs(p);
}

#endif
