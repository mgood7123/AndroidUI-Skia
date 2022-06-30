/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "include/xamarin/sk_managed_id_change_listener.h"
#include "include/xamarin/SkManaged_ID_Change_Listener.h"

#include "src/c/sk_types_priv.h"

static inline SkManaged_ID_Change_Listener* AsSkManaged_ID_Change_Listener(sk_id_change_listener_t* d) {
    return reinterpret_cast<SkManaged_ID_Change_Listener*>(d);
}
static inline sk_id_change_listener_t* ToSkManaged_ID_Change_Listener(SkManaged_ID_Change_Listener* d) {
    return reinterpret_cast<sk_id_change_listener_t*>(d);
}

static sk_id_change_listener_procs_t gProcs;

void changed(SkManaged_ID_Change_Listener* d, void* context) {
    if (gProcs.fChanged) {
        gProcs.fChanged(ToSkManaged_ID_Change_Listener(d), context);
    }
}

void destroy(SkManaged_ID_Change_Listener* d, void* context) {
    if (gProcs.fDestroy) {
        gProcs.fDestroy(ToSkManaged_ID_Change_Listener(d), context);
    }
}

sk_id_change_listener_t* sk_managed_id_change_listener_new(void* context) {
    return ToSkManaged_ID_Change_Listener(new SkManaged_ID_Change_Listener(context));
}

void sk_managed_id_change_listener_delete(sk_id_change_listener_t* d) {
    delete AsSkManaged_ID_Change_Listener(d);
}

void sk_managed_id_change_listener_mark_should_deregister(sk_id_change_listener_t* d) {
    AsSkManaged_ID_Change_Listener(d)->markShouldDeregister();
}

bool sk_managed_id_change_listener_should_deregister(sk_id_change_listener_t* d) {
    return AsSkManaged_ID_Change_Listener(d)->shouldDeregister();
}

void sk_managed_id_change_listener_set_procs(sk_id_change_listener_procs_t procs) {
    gProcs = procs;

    SkManaged_ID_Change_Listener::Procs p;
    p.fChanged = changed;
    p.fDestroy = destroy;

    SkManaged_ID_Change_Listener::setProcs(p);
}
