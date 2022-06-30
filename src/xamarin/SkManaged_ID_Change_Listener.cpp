/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/xamarin/SkManaged_ID_Change_Listener.h"

SkManaged_ID_Change_Listener::Procs SkManaged_ID_Change_Listener::fProcs;

void SkManaged_ID_Change_Listener::setProcs(SkManaged_ID_Change_Listener::Procs procs) {
    fProcs = procs;
}

SkManaged_ID_Change_Listener::SkManaged_ID_Change_Listener(void* context) {
    fContext = context;
}

SkManaged_ID_Change_Listener::~SkManaged_ID_Change_Listener() {
    if (fProcs.fDestroy) {
        fProcs.fDestroy(this, fContext);
    }
}

void SkManaged_ID_Change_Listener::changed() {
    if (fProcs.fChanged) {
        fProcs.fChanged(this, fContext);
    }
}
