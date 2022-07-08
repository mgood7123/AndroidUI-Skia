/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/xamarin/sk_managedidchangelistener.h"
#include "include/xamarin/SkManagedIDChangeListener.h"

#include "include/xamarin/sk_managedidchangelistenerlist.h"
#include "include/xamarin/SkManagedIDChangeListener_List.h"

#include "src/c/sk_types_priv.h"

static inline SkManagedIDChangeListener* AsSkManagedIDChangeListener(sk_idchangelistener_t* d) {
    return reinterpret_cast<SkManagedIDChangeListener*>(d);
}
static inline SkManagedIDChangeListener_List* AsSkManagedIDChangeListener_List(sk_idchangelistenerlist_t* d) {
    return reinterpret_cast<SkManagedIDChangeListener_List*>(d);
}
static inline sk_idchangelistenerlist_t* ToSkManagedIDChangeListener_List(SkManagedIDChangeListener_List* d) {
    return reinterpret_cast<sk_idchangelistenerlist_t*>(d);
}

static sk_idchangelistenerlist_procs_t gProcs;

void destroy_List(SkManagedIDChangeListener_List* d, void* context) {
    if (gProcs.fDestroy) {
        gProcs.fDestroy(ToSkManagedIDChangeListener_List(d), context);
    }
}

sk_idchangelistenerlist_t* sk_managedidchangelistenerlist_new(void* context) {
    return ToSkManagedIDChangeListener_List(new SkManagedIDChangeListener_List(context));
}

void sk_managedidchangelistenerlist_delete(sk_idchangelistenerlist_t* d) {
    delete AsSkManagedIDChangeListener_List(d);
}

void sk_managedidchangelistenerlist_add(sk_idchangelistenerlist_t* d, sk_idchangelistener_t* listener, bool single_threaded) {
    AsSkManagedIDChangeListener_List(d)->add(sk_sp(AsSkManagedIDChangeListener(listener)),
                                                single_threaded);
}

int32_t sk_managedidchangelistenerlist_count(sk_idchangelistenerlist_t* d) {
    return AsSkManagedIDChangeListener_List(d)->count();
}

void sk_managedidchangelistenerlist_changed(sk_idchangelistenerlist_t* d, bool single_threaded) {
    AsSkManagedIDChangeListener_List(d)->changed(single_threaded);
}

void sk_managedidchangelistenerlist_reset(sk_idchangelistenerlist_t* d, bool single_threaded) {
    AsSkManagedIDChangeListener_List(d)->reset(single_threaded);
}

void sk_managedidchangelistenerlist_set_procs(sk_idchangelistenerlist_procs_t procs) {
    gProcs = procs;

    SkManagedIDChangeListener_List::Procs p;
    p.fDestroy = destroy_List;

    SkManagedIDChangeListener_List::setProcs(p);
}
