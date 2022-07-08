/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/xamarin/SkManagedIDChangeListener_List.h"

SkManagedIDChangeListener_List::Procs SkManagedIDChangeListener_List::fProcs;

void SkManagedIDChangeListener_List::setProcs(SkManagedIDChangeListener_List::Procs procs) {
    fProcs = procs;
}

SkManagedIDChangeListener_List::SkManagedIDChangeListener_List(void* context) {
    fContext = context;
}

SkManagedIDChangeListener_List::~SkManagedIDChangeListener_List() {
    if (fProcs.fDestroy) {
        fProcs.fDestroy(this, fContext);
    }
}
