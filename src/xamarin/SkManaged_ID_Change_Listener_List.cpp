/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/xamarin/SkManaged_ID_Change_Listener_List.h"

SkManaged_ID_Change_Listener_List::Procs SkManaged_ID_Change_Listener_List::fProcs;

void SkManaged_ID_Change_Listener_List::setProcs(SkManaged_ID_Change_Listener_List::Procs procs) {
    fProcs = procs;
}

SkManaged_ID_Change_Listener_List::SkManaged_ID_Change_Listener_List(void* context) {
    fContext = context;
}

SkManaged_ID_Change_Listener_List::~SkManaged_ID_Change_Listener_List() {
    if (fProcs.fDestroy) {
        fProcs.fDestroy(this, fContext);
    }
}
