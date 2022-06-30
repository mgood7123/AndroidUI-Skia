/*
 * Copyright 2022 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkManaged_ID_Change_Listener_h
#define SkManaged_ID_Change_Listener_h

#include "include/private/SkIDChangeListener.h"
#include "include/core/SkTypes.h"

class SkIDChangeListener;

class SK_API SkManaged_ID_Change_Listener;

// delegate declarations

// managed Allocator
class SkManaged_ID_Change_Listener : public SkIDChangeListener {
public:
    SkManaged_ID_Change_Listener(void* context);

    ~SkManaged_ID_Change_Listener() override;

public:
    typedef void       (*ChangedProc)              (SkManaged_ID_Change_Listener* d, void* context);
    typedef void       (*DestroyProc)              (SkManaged_ID_Change_Listener* d, void* context);

    struct Procs {
        ChangedProc fChanged = nullptr;
        DestroyProc fDestroy = nullptr;
    };

    static void setProcs(Procs procs);

protected:
    void changed() override;

private:
    void* fContext;
    static Procs fProcs;

    typedef SkIDChangeListener INHERITED;
};


#endif
