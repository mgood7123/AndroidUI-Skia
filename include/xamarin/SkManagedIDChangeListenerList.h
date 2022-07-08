/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkManagedIDChangeListener_List_h
#define SkManagedIDChangeListener_List_h

#include "include/private/SkIDChangeListener.h"
#include "include/core/SkTypes.h"

class SK_API SkManagedIDChangeListener_List;

// delegate declarations

// managed Allocator
class SkManagedIDChangeListener_List : public SkIDChangeListener::List {
public:
    SkManagedIDChangeListener_List(void* context);

    ~SkManagedIDChangeListener_List();

    typedef void (*DestroyProc)(SkManagedIDChangeListener_List* d, void* context);

    struct Procs {
        DestroyProc fDestroy = nullptr;
    };

    static void setProcs(Procs procs);

private:
    void* fContext;
    static Procs fProcs;

    typedef SkIDChangeListener::List INHERITED;
};


#endif
