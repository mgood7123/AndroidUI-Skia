/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/xamarin/sk_managed_id_change_listener.h"
#include "include/xamarin/SkManaged_ID_Change_Listener.h"

#include "include/xamarin/sk_managed_id_change_listener_list.h"
#include "include/xamarin/SkManaged_ID_Change_Listener_List.h"

#include "src/c/sk_types_priv.h"

static inline SkManaged_ID_Change_Listener* AsSkManaged_ID_Change_Listener(sk_id_change_listener_t* d) {
    return reinterpret_cast<SkManaged_ID_Change_Listener*>(d);
}
static inline SkManaged_ID_Change_Listener_List* AsSkManaged_ID_Change_Listener_List(sk_id_change_listener_list_t* d) {
    return reinterpret_cast<SkManaged_ID_Change_Listener_List*>(d);
}
static inline sk_id_change_listener_list_t* ToSkManaged_ID_Change_Listener_List(SkManaged_ID_Change_Listener_List* d) {
    return reinterpret_cast<sk_id_change_listener_list_t*>(d);
}

static sk_id_change_listener_list_procs_t gProcs;

void destroy_List(SkManaged_ID_Change_Listener_List* d, void* context) {
    if (gProcs.fDestroy) {
        gProcs.fDestroy(ToSkManaged_ID_Change_Listener_List(d), context);
    }
}

sk_id_change_listener_list_t* sk_managed_id_change_listener_list_new(void* context) {
    return ToSkManaged_ID_Change_Listener_List(new SkManaged_ID_Change_Listener_List(context));
}

void sk_managed_id_change_listener_list_delete(sk_id_change_listener_list_t* d) {
    delete AsSkManaged_ID_Change_Listener_List(d);
}

void sk_managed_id_change_listener_list_add(sk_id_change_listener_list_t* d, sk_id_change_listener_t* listener, bool single_threaded) {
    AsSkManaged_ID_Change_Listener_List(d)->add(sk_sp(AsSkManaged_ID_Change_Listener(listener)),
                                                single_threaded);
}

int32_t sk_managed_id_change_listener_list_count(sk_id_change_listener_list_t* d) {
    return AsSkManaged_ID_Change_Listener_List(d)->count();
}

void sk_managed_id_change_listener_list_changed(sk_id_change_listener_list_t* d, bool single_threaded) {
    AsSkManaged_ID_Change_Listener_List(d)->changed(single_threaded);
}

void sk_managed_id_change_listener_list_reset(sk_id_change_listener_list_t* d, bool single_threaded) {
    AsSkManaged_ID_Change_Listener_List(d)->reset(single_threaded);
}

void sk_managed_id_change_listener_list_set_procs(sk_id_change_listener_list_procs_t procs) {
    gProcs = procs;

    SkManaged_ID_Change_Listener_List::Procs p;
    p.fDestroy = destroy_List;

    SkManaged_ID_Change_Listener_List::setProcs(p);
}
