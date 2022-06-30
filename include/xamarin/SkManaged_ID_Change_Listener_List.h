/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkManaged_ID_Change_Listener_List_h
#define SkManaged_ID_Change_Listener_List_h

#include "include/private/SkIDChangeListener.h"
#include "include/core/SkTypes.h"

class SK_API SkManaged_ID_Change_Listener_List;

// delegate declarations

// managed Allocator
class SkManaged_ID_Change_Listener_List : public SkIDChangeListener::List {
public:
    SkManaged_ID_Change_Listener_List(void* context);

    ~SkManaged_ID_Change_Listener_List();

    typedef void (*DestroyProc)(SkManaged_ID_Change_Listener_List* d, void* context);

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
